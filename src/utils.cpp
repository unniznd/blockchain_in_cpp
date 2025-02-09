#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include "utils.h"

std::string sha256(const std::string &data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.length(), hash);

    std::ostringstream oss;
    for (unsigned char c : hash)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    
    return oss.str();
}
