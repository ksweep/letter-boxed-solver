//
//  SolutionCreator.cpp
//  letter-boxed-solver
//
//  Created by Breeze on 5/24/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#include "SolutionCreator.hpp"

#include "BoardMove.hpp"
#include "GameBoard.hpp"
#include "GameLetter.hpp"

SolutionCreator::SolutionCreator(GameBoard& b, std::vector<BoardMove>& m) : board_(b), moves_(m) {
    // sort by descending length
    std::sort(moves_.begin(), moves_.end(), []
    (const BoardMove& first, BoardMove& second){
        return first.letters.size() > second.letters.size();
    });
    for (int i = 0; i < b.letters.size(); i++) {
        letter_ids_.insert(i);
    }
}

bool SolutionCreator::IsSolution(std::vector<BoardMove>& test_solution) {
    std::unordered_set<int> verify_set = letter_ids_;
    for (int move_index = 0; move_index < test_solution.size(); move_index++) {
        if (move_index > 0 && test_solution[move_index].letters.front().character != test_solution[move_index - 1].letters.back().character) {
            return false;
        }
        for (const GameLetter& letter : test_solution[move_index].letters) {
            verify_set.erase(letter.id);
        }
    }
    return verify_set.empty();
}

void SolutionCreator::FindBestMoves(std::vector<BoardMove>& build_solution, std::vector<std::vector<BoardMove>>& all_best_solutions, int& best_size, std::unordered_set<std::string>& build_used_moves) {
    if (build_solution.size() > 0 && IsSolution(build_solution)) {
        const int solution_size = (int)build_solution.size();
        if (solution_size == best_size) {
            all_best_solutions.push_back(build_solution);
        } else if (solution_size < best_size) {
            all_best_solutions.clear();
            all_best_solutions.push_back(build_solution);
            best_size = solution_size;
        }
    } else {
        for (const BoardMove& possible_move : moves_) {
            if (build_solution.size() > 0 && possible_move.letters.front().character != build_solution.back().letters.back().character) {
                continue;
            }
            if (build_solution.size() + 1 > best_size) {
                continue;
            }
            if (build_used_moves.find(possible_move.word) != build_used_moves.end()) {
                continue;
            }

            // try possible_move
            build_used_moves.insert(possible_move.word);
            build_solution.push_back(possible_move);

            // recurse
            FindBestMoves(build_solution, all_best_solutions, best_size, build_used_moves);

            // undo possible_move
            build_solution.pop_back();
            build_used_moves.erase(possible_move.word);
        }
    }
}

std::vector<std::vector<std::string>> SolutionCreator::BestSolutions() {
    std::vector<BoardMove> build_solution;
    std::vector<std::vector<BoardMove>> all_best_solutions;
    int best_size = std::numeric_limits<int>::max();
    std::unordered_set<std::string> build_used_moves;
    FindBestMoves(build_solution, all_best_solutions, best_size, build_used_moves);

    std::vector<std::vector<std::string>> result;
    for (const std::vector<BoardMove>& best_solution : all_best_solutions) {
        std::vector<std::string> current_solution;
        for (const BoardMove& move : best_solution) {
            current_solution.push_back(move.word);
        }
        result.push_back(current_solution);
    }
    return result;
}
