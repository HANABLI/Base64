/**
 * @file Base64.cpp
 * 
 * This modul is an implementation of the Base64 
 * encoding/decoding functions
 * 
 * © 2024 by Hatem Nabli
 */

#include "Base64/Base64.hpp"
#include <sstream>
namespace {
    /**
     * This is used to find the Base64 encoding of one 6-bit
     * input group
     */
    const char EncodingTable[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    /**
     * This is used to find the Base64 decoding of one 6-bit 
     * input group
     */
    /*   0 A            17 R            34 i            51 z
         1 B            18 S            35 j            52 0
         2 C            19 T            36 k            53 1
         3 D            20 U            37 l            54 2
         4 E            21 V            38 m            55 3
         5 F            22 W            39 n            56 4
         6 G            23 X            40 o            57 5
         7 H            24 Y            41 p            58 6
         8 I            25 Z            42 q            59 7
         9 J            26 a            43 r            60 8
        10 K            27 b            44 s            61 9
        11 L            28 c            45 t            62 +
        12 M            29 d            46 u            63 /
        13 N            30 e            47 v
        14 O            31 f            48 w         (pad) =
        15 P            32 g            49 x
        16 Q            33 h            50 y */
    std::map< char, uint8_t > DecodingTable() {
        std::map< char, uint8_t > decodingTable;
        uint8_t num1, num2, num3;
        for (size_t i = 65; i <= 90; ++i ) {
            num1 = uint8_t(i-65);
            decodingTable.insert({static_cast<char>(i), num1});
        }
        for (size_t i = 97; i <= 122; ++i) {
            num2 = (uint8_t(i - 96) + num1);
            decodingTable.insert({static_cast<char>(i), num2});
        }
        for (size_t i = 48; i <= 57; ++i) {
            num3 = (uint8_t(i - 47) + num2);
            decodingTable.insert({static_cast<char>(i), num3});
        }
        decodingTable.insert({'+', num3++});
        decodingTable.insert({'/', num3++});
        return decodingTable;
    }
}

namespace Base64 {

     std::string EncodeToBase64(const std::vector< uint8_t >& data) {
        std::ostringstream output;
        size_t bits = 0;
        uint32_t buffer = 0;
        for (auto datum: data) {
            buffer <<= 8;
            buffer += (uint32_t)datum;
            bits += 8;
            while (bits >= 6) {
                output << EncodingTable[(buffer >> (bits - 6)) & 0x3f];
                buffer &= ~(0x3f << (bits - 6));
                bits -= 6;
            }
        }
        if ((data.size() % 3) == 1) {
            buffer <<= 4;
            output << EncodingTable[buffer & 0x3f];
            output << "==";
        } else if ((data.size() % 3) == 2) {
            buffer <<= 2;
            output << EncodingTable[buffer & 0x3f];
            output << '=';
        }
        return output.str();
     }

     std::string EncodeToBase64(const std::string& data) {
        return EncodeToBase64(
            std::vector < uint8_t >(
                data.begin(),
                data.end()
            )
        );
     }

     std::string Base64::DecodeFromBase64(const std::vector< uint8_t >& data) {
        const auto decodingTablte = DecodingTable();
        std::ostringstream output;
        uint32_t buffer = 0;
        size_t bits = 0;
        for (auto datum: data) {
            const auto entry = decodingTablte.find(datum);
            uint32_t group = 0;
            if (entry != decodingTablte.end()) {
                group = entry->second;
            }
            buffer <<= 6;
            bits += 6;
            buffer += group;
            if (bits >= 8) {
                if (datum != '=') {
                    output << (char)(buffer >> (bits - 8));
                }
                buffer &= ~(0xff << (bits - 8));
                bits -= 8;
            }
        }   
        return output.str();
     }

     std::string DecodeFromBase64(const std::string& data) {
        return DecodeFromBase64(
            std::vector < uint8_t >(
                data.begin(),
                data.end()
            )
        );
     }
}
