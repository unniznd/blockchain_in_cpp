#include<iostream>
#include <ctime>


#include "blockchain.h"
#include "block.h"



Blockchain::Blockchain(int timestamp){
    this->create_genesis_block(timestamp);
}

void Blockchain::add_block(std::string data){
    std::time_t time = std::time(nullptr);
    int timestamp = static_cast<int>(time);
    int blocknumber = blocks.size();
    std::string prev_block_hash = this->get_block_hash(blocknumber - 1);
    Block block(blocknumber, timestamp, data, prev_block_hash);
    block.generate_hash();
    blocks.emplace_back(block);
    return;
}

void Blockchain::create_genesis_block(int timestamp){
    if(blocks.size()) return;
    Block block(0, timestamp, 
            "Here it's started", "02b8e8fa335c997c6213c02cb982f143a4be0d2bf5fb05e16973418140fb5f9c");
    block.generate_hash();
    this->blocks.emplace_back(block);
}

std::string Blockchain::get_block_hash(int blocknumber){
    int size = blocks.size();
    if(blocknumber<size) return blocks[blocknumber].get_hash();
    return "";
}