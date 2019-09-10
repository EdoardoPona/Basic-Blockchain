//
//  Block.cpp
//  Blockchain
//
//  Created by Edoardo Pona on 23/08/2019.
//  Copyright © 2019 Edoardo Pona. All rights reserved.
//

#include "Block.hpp"
#include "sha256.hpp"
#include <vector>
#include <string>
#include <sstream>

Block::Block(std::string hashPrevBlock, std::string new_data, int n_time, int n_bits){
    HashPrevBlock = hashPrevBlock;
    data = new_data;
    nBits = n_bits;
    nTime = n_time;
    DataHash = sha256(data);
    
}

std::stringstream Block::get_header(){
    std::stringstream ss;
    ss << nVersion << HashPrevBlock << DataHash << nTime << nBits << nNonce;
    return ss;
}

std::string Block::get_block_hash(){
    return sha256(sha256(get_header().str()));
}

void Block::mine(){
    char cstr[nBits+1];
    for (uint32_t i=0; i<nBits; i++){
        cstr[i] = '0';
    }
    cstr[nBits] = '\0';
    std::string str(cstr);
    
    do {
        nNonce ++;
    } while (get_block_hash().substr(0, nBits) != str);
}
