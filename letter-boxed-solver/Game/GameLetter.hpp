//
//  GameLetter.hpp
//  letter-boxed-solver
//
//  Created by Breeze on 5/24/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#ifndef GameLetter_hpp
#define GameLetter_hpp

class GameLetter {
public:
    GameLetter(char _character, int _side, int _id) {
        character = _character;
        side = _side;
        id = _id;
    }
    char character;
    int side;
    int id;
};

#endif /* GameLetter_hpp */
