//
//  WordListCreator.cpp
//  letter-boxed-solver
//
//  Created by Breeze on 5/24/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#include "WordListCreator.hpp"

#include "BoardMove.hpp"
#include "GameBoard.hpp"
#include "GameLetter.hpp"
#include "TrieNode.hpp"

WordListCreator::WordListCreator(GameBoard& game_board, TrieNode* trie_root) : game_board_(game_board), trie_root_(trie_root) {}

TrieNode* WordListCreator::NodeFromLetters(TrieNode* trie_root, std::vector<GameLetter>& build_letters) {

    // NOTE: if we get rid of prefix variable in TrieNode, we need to build the string here

    TrieNode* result = trie_root;
    for (GameLetter& letter : build_letters) {
        if (result->children[letter.character - 'a'] != nullptr) {
            result = result->children[letter.character - 'a'];
        } else {
            return nullptr;
        }
    }
    return result;
}

// backtracking algorithm to find all words
void WordListCreator::FindAllWords(std::vector<GameLetter>& build_letters, std::vector<BoardMove>& words) {
    TrieNode* current_node = NodeFromLetters(trie_root_, build_letters);

    if (current_node->is_word && build_letters.size() > 2) {
        words.push_back(BoardMove(current_node->prefix, build_letters));
    }

    for (const GameLetter& test_letter : game_board_.letters) {
        // skip if doesn't follow Letter Box rules
        if (!build_letters.empty() && build_letters.back().side == test_letter.side) {
            continue;
        }

        // skip if not in trie
        if (current_node->children[test_letter.character - 'a'] == nullptr) {
            continue;
        }

        // add pair
        build_letters.push_back(test_letter);

        // recurse
        FindAllWords(build_letters, words);

        // undo add pair
        build_letters.pop_back();
    }
}

std::vector<BoardMove> WordListCreator::FindAllMoves() {
    std::vector<GameLetter> build_letters;
    std::vector<BoardMove> all_moves;

    FindAllWords(build_letters, all_moves);

    return all_moves;
}
