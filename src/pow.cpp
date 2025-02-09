#include<iostream>
#include<climits>
#include "block.h"
#include "pow.h"
#include "utils.h"

int pow(Block* block){
    for(int i = 0; i<INT_MAX; i++){
        std::string block_data = block->get_data(i);
        std::string hash = sha256(block_data);
        if(hash.substr(0, 4) == "0000") return i;
    }
    return INT_MAX;
}