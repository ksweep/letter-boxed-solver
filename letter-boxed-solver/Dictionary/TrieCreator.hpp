//
//  TrieCreator.hpp
//  letter-boxed-solver
//
//  Created by Breeze on 5/24/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#ifndef TrieCreator_hpp
#define TrieCreator_hpp

#include <string>

class TrieNode;

class TrieCreator {
public:
    static TrieNode* MakeTrie(std::string file_name);
};

#endif /* TrieCreator_hpp */
