#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std; 
bool isCowInMill(const int S, const int cow, vector<vector<int>>& board) {
    // Define the eight possible mills as sets of three indices
    std::set<std::vector<int>> mills = {
        {10, 0, 1, 2},{11, 0, 1, 2},{12, 0, 1, 2},
        {10, 2, 3, 4},{11, 2, 3, 4},{12, 2, 3, 4},
        {10, 4, 5, 6},{11, 4, 5, 6},{12, 4, 5, 6},
        {10, 6, 7, 0},{11, 6, 7, 0},{12, 6, 7, 0},
        
        {10, 0, 0, 0},{11, 0, 0, 0},{12, 0, 0, 0},
        {10, 1, 1, 1},{11, 1, 1, 1},{12, 1, 1, 1},
        {10, 2, 2, 2},{11, 2, 2, 2},{12, 2, 2, 2},
        {10, 3, 3, 3},{11, 3, 3, 3},{12, 3, 3, 3},
        {10, 4, 4, 4},{11, 4, 4, 4},{12, 4, 4, 4},
        {10, 5, 5, 5},{11, 5, 5, 5},{12, 5, 5, 5},
        {10, 6, 6, 6},{11, 6, 6, 6},{12, 6, 6, 6},
        {10, 7, 7, 7},{11, 7, 7, 7},{12, 7, 7, 7},

    };

    // Loop through the mills and check if the cow is in any of them
    for (auto mill : mills) {
    	if (std::find(mill.begin(), mill.end(), S) != mill.end() ){
        if (std::find(mill.begin(), mill.end(), cow) != mill.end()) {
            // The cow is in this mill, so check if all other cows in the mill are the same
            int cow_type = board[S%10][cow];
            bool all_same = true;
            for (auto index : mill) {
            	if (index == 10 || index == 11 || index == 12){
            		continue;
            	}
                else if (board[S%10][index] != cow_type) {
                    all_same = false;
                    break;
                }
            }
            if (all_same) {
                // All cows in the mill are the same type as the given cow, so it is part of a mill
                return true;
            }
        }
       }
    }

    // The cow is not part of a mill
    return false;
}



