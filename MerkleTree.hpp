//
//  MerkleTree.hpp
//  Blockchain
//
//  Created by Edoardo Pona on 23/08/2019.
//  Copyright © 2019 Edoardo Pona. All rights reserved.
//

#ifndef MerkleTree_hpp
#define MerkleTree_hpp

#include <stdio.h>
#include <string>
#endif /* MerkleTree_hpp */


class MerkleNode{
public:
    std::string name;           // just to identify the node and verify the algorithm is correct
    std::string hash;
    MerkleNode* parent;
    MerkleNode* left;
    MerkleNode* right;
    int layer;                   // node level within the tree
};

typedef std::vector<MerkleNode> nv;

nv build_merkle_tree_layer(nv node_vector);
MerkleNode build_merkle_tree(nv leaf_vector);
