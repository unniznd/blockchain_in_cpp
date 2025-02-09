#include<iostream>

#ifndef block_header
#define block_header

class Block{
    int blocknumber;
    int timestamp;
    std::string data;
    std::string prev_block_hash; 
    std::string hash;

    

public:
    Block(int blocknumber, int timestamp, std::string data, std::string prev_block_hash);

    void generate_hash();
    std::string get_hash();
    std::string get_data(int nonce);
};

#endif