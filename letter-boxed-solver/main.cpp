//
//  main.cpp
//  letter-boxed-solver
//
//  Created by Breeze on 5/23/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#include <functional>
#include <iostream>
#include <vector>

#include "BoardMove.hpp"
#include "GameBoard.hpp"
#include "GameLetter.hpp"
#include "SolutionCreator.hpp"
#include "TrieCreator.hpp"
#include "TrieNode.hpp"
#include "WordListCreator.hpp"

void TimeBlock (const std::function <void ()>& my_block) {
    const auto total_start = std::chrono::high_resolution_clock::now();
    my_block();
    const auto total_finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = total_finish - total_start;
    std::cout << "Total Elapsed Time: " << elapsed.count() << " s" << std::endl;
}

int main(int argc, const char * argv[]) {
    TimeBlock([] {
        TrieNode *trie_root = TrieCreator::MakeTrie("words.txt");

        GameBoard board = GameBoard("zgtomalnideb", 4);

        std::vector<BoardMove> all_moves = WordListCreator(board, trie_root).FindAllMoves();

        std::vector<std::vector<std::string>> best_solutions = SolutionCreator(board, all_moves).BestSolutions();

        for (const std::vector<std::string>& solution : best_solutions) {
            for (const std::string& solution_move : solution) {
                std::cout << solution_move << " ";
            }
            std::cout << std::endl;
        }
    });
    return 0;
}
