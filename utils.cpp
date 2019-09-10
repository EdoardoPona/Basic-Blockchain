//
//  utils.cpp
//  Blockchain
//
//  Created by Edoardo Pona on 23/08/2019.
//  Copyright © 2019 Edoardo Pona. All rights reserved.
//

#include "utils.hpp"
#include <vector>
#include <array>

typedef std::vector<int> vi;

HashTable::HashTable(){
    // filling the table with dummy LL, to start the list
    // not sure if this is necessary, might be able to just call table[i].left = NULL;
    
    for (int i=0; i<size; i++){
        LinkedListNode sentinel;
        sentinel.left = NULL;
        sentinel.right = NULL;
        table[i] = sentinel;
    }
}

void HashTable::add(Obj o){
    LinkedListNode LL;
    LL.object = o;
    
    LinkedListNode* latest = table[hash_function(o.key)].right;
    
    while (latest != NULL){
        latest = (*latest).right;
    }
    latest = &LL;
    LL.left = latest;
}

Obj HashTable::search(int k){
    LinkedListNode LL = table[hash_function(k)];
    int key = LL.object.key;
    while (key!=k){
        LL = *LL.right;
        key = LL.object.key;
    }
    return LL.object;
}

int HashTable::hash_function(int k){
    return k % size;
}
