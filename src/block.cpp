#include <sstream>

#include "block.h"
#include "utils.h"
#include "pow.h"

Block::Block(int blocknumber, int timestamp, std::string data, std::string prev_block_hash){
    this->blocknumber = blocknumber;
    this->timestamp = timestamp;
    this->data = data;
    this->prev_block_hash =prev_block_hash;
}

void Block::generate_hash(){
    int nonce = pow(this);
    std::string result = this->get_data(nonce);
    this->hash = sha256(result);
    this->nonce = nonce;
}

std::string Block::get_hash(){
    return this->hash;
}

std::string Block::get_data(int nonce){
    std::ostringstream oss;
    oss << this->blocknumber << this->timestamp << this->data << this->prev_block_hash << nonce;
    return oss.str();
}