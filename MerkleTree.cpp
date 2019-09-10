//
//  MerkleTree.cpp
//  Blockchain
//
//  Created by Edoardo Pona on 23/08/2019.
//  Copyright © 2019 Edoardo Pona. All rights reserved.
//

#include "MerkleTree.hpp"
#include <vector>
#include "sha256.hpp"
#include <iostream>

typedef std::vector<MerkleNode> nv;


nv build_merkle_tree_layer(nv node_vector){
    nv next_layer;
    for (int i=0; i<node_vector.size(); i=i+2){
        MerkleNode parent;
        std::string hash = sha256(node_vector[i].hash + node_vector[i+1].hash);
        parent.hash = hash;
        parent.left = &node_vector[i];
        parent.right = &node_vector[i+1];
        parent.name = node_vector[i].name + node_vector[i+1].name;
        next_layer.push_back(parent);
    }
    return next_layer;
}

MerkleNode build_merkle_tree(nv leaf_vector){
    
    while (leaf_vector.size() > 1){
        if (leaf_vector.size() % 2 == 1){
            MerkleNode new_node;
            new_node = leaf_vector[leaf_vector.size()-1];
            leaf_vector.push_back(new_node);
        }
        
        for (int i=0; i<leaf_vector.size(); i++){
            std::cout<<leaf_vector[i].name<<" ";
        }
        std::cout<<"\n";
        
        nv next_layer = build_merkle_tree_layer(leaf_vector);
        leaf_vector = next_layer;
        
    }
    
    return leaf_vector[0];
}

