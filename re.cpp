#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to check if a player has formed a mill and print the cows
void checkMill(const vector<string>& board, char player) {
    // Define the possible mills on the board as sets of three positions
    vector<vector<int>> mills = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    // Loop through all the mills to check if the player has formed a mill
    for (auto mill : mills) {
        bool is_mill = true;
        for (auto pos : mill) {
            if (board[pos] != string(1, player)) {
                is_mill = false;
                break;
            }
        }
        if (is_mill) {
            // Print the cows that form the mill
            cout << "Mill formed by player " << player << " with cows: ";
            for (auto pos : mill) {
                cout << "S" << (pos / 3 + 1) << "i" << (pos % 3) << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    // Example board with three cows in a mill for player 1
    vector<string> board = {
        "1", "1", "",
        "",  "1", "",
        "",  "",  ""
    };

    // Check if player 1 has formed a mill and print the cows
    checkMill(board, '1');

    return 0;
}

