#pragma once

#include <vector>
#include <set>

namespace
{

    template<typename T>
    std::vector <std::vector<T>> allWaysToPick(const std::vector <T> &symbols, int num_to_pick, int begin_idx)
    {
        if (num_to_pick == 0) {
            std::vector <std::vector<T>> result;
            result.push_back(std::vector<T>());
            return result;
        }
        if (num_to_pick > (int) symbols.size() - begin_idx) {
            return std::vector < std::vector < T >> ();
        }
        if ((int) symbols.size() == begin_idx + 1) {
            std::vector <std::vector<T>> result;
            std::vector <T> list;
            list.push_back(symbols[begin_idx]);
            result.push_back(list);
            return result;
        }
        T first = symbols[begin_idx];
        auto solutions_excluding_first = allWaysToPick(symbols, num_to_pick, begin_idx + 1);
        auto solutions_including_first = allWaysToPick(symbols, num_to_pick - 1, begin_idx + 1);
        for (auto &solution : solutions_including_first) {
            solution.push_back(first);
        }
        std::vector <std::vector<T>> result;
        result.insert(result.end(), solutions_excluding_first.begin(), solutions_excluding_first.end());
        result.insert(result.end(), solutions_including_first.begin(), solutions_including_first.end());
        return result;
    }

    template<typename T>
    std::set <std::vector<T>> uniquePicks(const std::vector <std::vector<T>> &picks)
    {
        std::set <std::vector<T>> result;
        for (auto &pick : picks) {
            result.insert(pick);
        }
        return result;
    }
}

/**
 * Returns all possible ways to pick the specified number of objects
 * from the symbols provided.
 */
template<typename T>
std::set <std::vector<T>> waysToPick(const std::vector <T> &symbols, int num_to_pick)
{
    auto all_picks = allWaysToPick(symbols, num_to_pick, 0);
    return uniquePicks<T>(all_picks);
}



