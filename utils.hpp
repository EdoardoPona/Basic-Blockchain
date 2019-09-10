//
//  utils.hpp
//  Blockchain
//
//  Created by Edoardo Pona on 23/08/2019.
//  Copyright © 2019 Edoardo Pona. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <array>

class Obj{
public:
    int key;
    int satellite_data;
};


class LinkedListNode{
    // wrapper for Obj data used to build a linked list
public:
    LinkedListNode* right;
    LinkedListNode* left;
    Obj object;
};


class HashTable{
    // Universe: [0, 1000]
    // m = 100 so hash(k) = K % 100
    
public:
    static const int size = 100;
    HashTable();
    void add(Obj o);
    Obj search(int k);
private:
    std::array<LinkedListNode, size> table;
    int hash_function(int k);
};
    

#endif /* utils_hpp */
