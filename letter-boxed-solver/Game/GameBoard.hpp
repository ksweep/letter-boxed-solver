//
//  GameBoard.hpp
//  letter-boxed-solver
//
//  Created by Breeze on 5/24/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include "GameLetter.hpp"

class GameBoard {
public:
    // letters start from top left and go clockwise
    GameBoard(const std::string& characters, const int number_of_sides) {
        const int num_characters = (int)characters.size();
        assert(num_characters % number_of_sides == 0);
        const int characters_per_side = num_characters / number_of_sides;
        for (int side_index = 0; side_index < number_of_sides; side_index++) {
            for (int i = 0; i < characters_per_side; i++) {
                const int index = side_index * characters_per_side + i;
                letters.push_back(GameLetter(characters[index], side_index, index));
            }
        }
    }
    std::vector<GameLetter> letters;
};

#endif /* GameBoard_hpp */
