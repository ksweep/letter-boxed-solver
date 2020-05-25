//
//  BoardMove.hpp
//  letter-boxed-solver
//
//  Created by Breeze on 5/24/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#ifndef BoardMove_hpp
#define BoardMove_hpp

#include <string>
#include <vector>

#include "GameLetter.hpp"

class BoardMove {
public:
    BoardMove(std::string& s, std::vector<GameLetter>& p) {
        word = s;
        letters = p;
    }
    std::string word;
    std::vector<GameLetter> letters;
};

#endif /* BoardMove_hpp */
