#ifndef BASE64_HPP
#define BASE64_HPP
/**
 * @file Base64.hpp
 *
 * This module define the Base64 class
 *
 * © 2024 by Hatem Nabli
 */
#include <stdint.h>
#include <map>
#include <string>
#include <vector>

namespace Base64
{
    /**
     * This function encodes the given data using the Base64 algorithm.
     *
     * @param[in] data
     *      This is the data to encode using the Base64 algorithm.
     *
     * @return
     *      returns a Base64 encoding of the given data
     *
     */
    std::string EncodeToBase64(const std::vector<uint8_t>& data);

    /**
     * This function encodes the given data using the Base64 algorithm.
     *
     * @param[in] data
     *      This is the data to encode using the Base64 algorithm.
     *
     * @return
     *      returns a Base64 encoding of the given data
     *
     */
    std::string EncodeToBase64(const std::string& data);

    /**
     * This function encodes the given data using the Base64 algorithm.
     *
     * @param[in] data
     *      This is the data to encode using the Base64 algorithm.
     *
     * @return
     *      returns a Base64 encoding of the given data
     *
     */
    std::string DecodeFromBase64(const std::vector<uint8_t>& data);

    /**
     * This function decodes the given data using the Base64 algorithm.
     *
     * @param[in] data
     *      This is the data to decode using the Base64 algorithm.
     *
     * @return
     *      returns a Base64 decoding of the given data
     *
     */
    std::string DecodeFromBase64(const std::string& data);
}  // namespace Base64

#endif /* BASE64_HPP */