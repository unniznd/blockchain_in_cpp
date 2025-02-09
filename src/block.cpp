#include <sstream>

#include "block.h"
#include "utils.h"

Block::Block(int blocknumber, int timestamp, std::string data, std::string prev_block_hash){
    this->blocknumber = blocknumber;
    this->timestamp = timestamp;
    this->data = data;
    this->prev_block_hash =prev_block_hash;
}

void Block::generate_hash(){
    std::ostringstream oss;
    oss << this->blocknumber << this->timestamp << this->data << this->prev_block_hash;
    std::string result = oss.str();
    this->hash = sha256(result);
}

std::string Block::get_hash(){
    return this->hash;
}