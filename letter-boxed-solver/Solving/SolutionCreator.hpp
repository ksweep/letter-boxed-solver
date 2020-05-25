//
//  SolutionCreator.hpp
//  letter-boxed-solver
//
//  Created by Breeze on 5/24/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#ifndef SolutionCreator_hpp
#define SolutionCreator_hpp

#include <string>
#include <unordered_set>
#include <vector>

class GameBoard;
class BoardMove;

class SolutionCreator {
private:
    std::vector<BoardMove> moves_;
    GameBoard& board_;
    std::unordered_set<int> letter_ids_;

    void FindBestMoves(std::vector<BoardMove>& build_solution, std::vector<std::vector<BoardMove>>& all_best_solutions, int& best_size, std::unordered_set<std::string>& build_used_moves);
    bool IsSolution(std::vector<BoardMove>& test_solution);

public:
    SolutionCreator(GameBoard& b, std::vector<BoardMove>& m);

    std::vector<std::vector<std::string>> BestSolutions();
};

#endif /* SolutionCreator_hpp */
