//
//  Block.hpp
//  Blockchain
//
//  Created by Edoardo Pona on 23/08/2019.
//  Copyright © 2019 Edoardo Pona. All rights reserved.
//

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>

typedef std::vector<std::string> str_vec;

class Block{
public:
    Block(std::string hashPrevBlock, std::string new_data, int n_time, int n_bits);
    int nVersion = 0;                   // version of the block, ones that don't agree are ignored
    std::string HashPrevBlock;          // should really be uint256, but the implementation of sha256 outputs a string
    std::string DataHash;               // also string is 24 bytes, uint256 is 32
    unsigned int nTime;                 // timestamp in unix format of approximate block creation time
    unsigned int nBits;                 // Target T for the proof of work problem in compact format
    unsigned int nNonce;                // Nonce allowing variations for solving the proof of work problem
    
    std::string data;       // this would usually be the transaction vector, make this a vector of objects and do something with it
    std::stringstream get_header();
    std::string get_block_hash();
    void mine();
    
};

#endif /* Block_hpp */




