//
//  Blockchain.cpp
//  Blockchain
//
//  Created by Edoardo Pona on 23/08/2019.
//  Copyright © 2019 Edoardo Pona. All rights reserved.
//

#include "Blockchain.hpp"
#include <time.h>
#include <iostream>

void Blockchain::add_block(Block* block){
    blocks.push_back(*block);
}

Block Blockchain::get_latest_block(){
    return blocks[blocks.size()-1];
}

int Blockchain::get_difficulty(){
    return nDifficulty;
}

void Blockchain::set_difficulty(int difficulty){
    nDifficulty = difficulty;
}
