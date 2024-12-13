/**
 * @file Base64Tests.cpp
 * 
 * This module contains tests for Base64 functions
 * 
 * © 2024 by Hatem Nabli
 */

#include <Base64/Base64.hpp>
#include <gtest/gtest.h>

TEST(Base64Tests, Base64Tests_Base64EncodeDecode__Test) {

    struct TestVector
    {
        std::string decoding;
        std::string encoding;
    };
    const std::vector< TestVector > testVectors{
        {"", ""},
        {"f" , "Zg=="},
        {"fo" , "Zm8="},
        {"foo" , "Zm9v"},
        {"foob" , "Zm9vYg=="},
        {"fooba" , "Zm9vYmE="},
        {"foobar", "Zm9vYmFy"},
    };   
    for(auto test: testVectors) {
        EXPECT_EQ(test.encoding, Base64::EncodeToBase64(test.decoding));
        EXPECT_EQ(test.decoding, Base64::DecodeFromBase64(test.encoding));
    }    
}