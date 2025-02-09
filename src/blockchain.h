#include<iostream>
#include "block.h"
#include <vector>

#ifndef blockchain_header
#define blockchain_header


class Blockchain{
    std::vector<Block> blocks;

public:
    Blockchain(int timestamp);

    void add_block(std::string data);
    void create_genesis_block(int timestamp);

    std::string get_block_hash(int blocknumber);
};

#endif