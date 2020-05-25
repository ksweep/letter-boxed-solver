//
//  WordListCreator.hpp
//  letter-boxed-solver
//
//  Created by Breeze on 5/24/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#ifndef WordListCreator_hpp
#define WordListCreator_hpp

#include <vector>

class GameBoard;
class TrieNode;
class BoardMove;
class GameLetter;

class WordListCreator {
private:
    TrieNode* NodeFromLetters(TrieNode* trie_root, std::vector<GameLetter>& build_letters);
    void FindAllWords(std::vector<GameLetter>& build_letters, std::vector<BoardMove>& words);

    const GameBoard& game_board_;
    TrieNode* trie_root_;
public:
    WordListCreator(GameBoard& game_board, TrieNode* trie_root);

    std::vector<BoardMove> FindAllMoves();
};

#endif /* WordListCreator_hpp */
