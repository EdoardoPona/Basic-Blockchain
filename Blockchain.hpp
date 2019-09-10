//
//  Blockchain.hpp
//  Blockchain
//
//  Created by Edoardo Pona on 23/08/2019.
//  Copyright © 2019 Edoardo Pona. All rights reserved.
//

#ifndef Blockchain_hpp
#define Blockchain_hpp

#include <stdio.h>
#include "Block.hpp"

typedef std::vector<Block> block_vec;


class Blockchain{
public:
    void add_block(Block* block);
    Block get_latest_block();
    int get_difficulty();
    void set_difficulty(int nDifficulty);
private:
    block_vec blocks;
    uint32_t nDifficulty;
};

#endif /* Blockchain_hpp */
