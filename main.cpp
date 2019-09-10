//
//  main.cpp
//  Blockchain
//
//  Created by Edoardo Pona on 19/08/2019.
//  Copyright © 2019 Edoardo Pona. All rights reserved.
//

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>

#include "sha256.hpp"
#include "utils.hpp"
#include "MerkleTree.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"


void add_data(Blockchain* blockchain, std::string data){
    int time = 0; // change this
    Block block = Block((*blockchain).get_latest_block().get_block_hash(), data, time, (*blockchain).get_difficulty());
    block.mine();
    (*blockchain).add_block(&block);
}

void add_genesis_block(Blockchain* blockchain, std::string data){
    int time = 0;   // change this
    std::string first_hash = sha256("the first hash");
    Block genesis_block = Block(first_hash, data, time, (*blockchain).get_difficulty());
    (*blockchain).add_block(&genesis_block);
    std::cout<<"Genesis Block added \ndata: "<<data<<"\n";
}


int main(int argc, const char * argv[]) {
    Blockchain ponachain;
    ponachain.set_difficulty(4);
    add_genesis_block(&ponachain, "25/08/2019 PonaChain says 'hello world' ");
    add_data(&ponachain, "Block 1");
    add_data(&ponachain, "Block 2");
    
    Block latest_block = ponachain.get_latest_block();
    std::cout<<latest_block.data<<"\n"<<latest_block.nNonce<<"\n"<<latest_block.get_block_hash()<<"\n";
    
    return 0;
}

