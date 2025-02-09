#include <iostream>
#include <ctime>
#include "blockchain.h"


int main() {
    std::time_t time = std::time(nullptr);
    int timestamp = static_cast<int>(time);
    Blockchain blockchain(timestamp);
    blockchain.add_block("Second block");
    std::cout<<blockchain.get_block_hash(1)<<std::endl;
    return 0;
}
