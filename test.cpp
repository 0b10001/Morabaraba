#include <iostream>
#include <vector>
#include "algo1.h"

using namespace std;

void display_board(vector<vector<int>>& board) {
    cout << "   1 2 3 4 5 6 7 8\n";
    for (int i = 0; i < 3; i++) {
        cout << i+1 << "  ";
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool place_piece(vector<vector<int>>& board, int player_piece,int row, int col) {

    row--;
    col--;
    if (board[row][col] == 0) {
        board[row][col] = player_piece;
        return true;
    } else {
        cout << "Cell already occupied. Try again.\n";
        return false;
    }
}

std::vector<std::vector<int>> myFunction () {
    vector<vector<int>> board(3, vector<int>(8, 0)); // Initialize board to all zeros
    int player_piece = 1;

    display_board(board);

    // Player 1 places pieces
    for (int i = 0; i < 24; i++) {
        bool placed = false;
        while (!placed) {
        	int S = randomNumber(3);
            	int j = randomNumber(8);
            placed = place_piece(board, player_piece,S,j);
        }
        player_piece ++;
        display_board(board);
    }
             
    return board;
}

