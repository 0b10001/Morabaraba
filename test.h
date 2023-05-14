#include <iostream>
#include <vector>
#include "algo1.h"
#include "mill.h"
#include <map>

using namespace std;


bool FOUND(vector<string> &P, string new_element,string new_element1,string new_element2){
	int a_found =0;
    int b_found = 0;
    int c_found = 0;

    for (int i = 0; i < P.size(); i++) {
        if (P[i] == new_element) {
            a_found = 1;
        }
        if (P[i] == new_element1) {
            b_found = 1;
        }if (P[i] == new_element2) {
            c_found = 1;
        }
    }
    if (a_found * b_found * c_found == 1){
    	return true;
    }return false;
}
void IfNotPresent(vector<string> &P, string new_element){
	bool is_present = false;
    for (int i = 0; i < P.size(); i++) {
        if (P[i] == new_element) {
            is_present = true;
            break;
        }
    }

    // Push back new_element if it is not already present
    if (!is_present) {
        P.push_back(new_element);
    }
}
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

void myFunction (int N) {

	// Create an empty map
    std::map<std::string, int> my_mapP1;
    std::map<std::string, int> my_mapP2;

	int counterP2 = N;
     ofstream output_file("morabarabaResults.txt", ios::app); 
     output_file << N <<endl;
    vector<vector<int>> board(3, vector<int>(8, 0)); // Initialize board to all zeros

    int player_piece = 1;
    
    vector<string> P1;
    vector<string> P2;

    display_board(board);

    // Player 1 places pieces
    for (int i = 0; i < 2 * N; i++) {
        bool placed = false;
        while (!placed) {
        	int S = randomNumber(3);
            	int j = randomNumber(8);
            placed = place_piece(board, player_piece,S,j);
            if (placed){
            	
            	ofstream output_file("morabarabaResults.txt", ios::app); 
            	// write to output file with a space before each new line
            	if (player_piece == 1){
            		if (S == 1){
            			string s = "P1 00-S0,i";  // if it's odd is player one
            			string ss = to_string(j-1);
            			
            			string s0 = "S0";
            			string I = to_string(j-1);
            			IfNotPresent(P1,s0);
            			P1.push_back(I);
            			
            			my_mapP1.insert(std::make_pair(s0, j-1));
            			
            			string sss = s + ss;
            			
            			if (FOUND(P1,"6","7","0")){
            				counterP2 --;
            				for (auto const& [key, value] : my_mapP2) {
		    				if(key == "S0"){
		    					std::cout << "IM INSIDE S0 ->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
		    						if(isCowInMill(10,value, board)){
		    							std::cout << "IM MILL S0 ->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
		    							output_file << sss << " " << "(mill = S0i6, S0i7, S0i0) P2 losses cow "<<"("<<key<<","<<"i"<<value<<")"<<" | "<<counterP2<< " left"<<endl;
		    							board[0][value] =0;
		    							break;
		    						}
		    						else if(key == "S1"){
		    						if(isCowInMill(11,value, board)){
		    						
		    							output_file << sss << " " << "(mill = S0i6, S0i7, S0i0) P2 losses cow "<<"("<<key<<","<<"i"<<value<<")"<<" | "<<counterP2<< " left"<<endl;
		    							board[0][value] = 0;
		    							break;
		    						}
		    					}
		    					else{
		    						if(isCowInMill(12,value, board)){
		    						
		    							output_file << sss << " " << "(mill = S0i6, S0i7, S0i0) P2 losses cow "<<"("<<key<<","<<"i"<<value<<")"<<" | "<<counterP2<< " left"<<endl;
		    							board[0][value] = 0;
		    							break;
		    						}
            						
            					}
		    					}

					}



            			}else{
            				output_file << sss <<endl;
            			}
            			
            			
            		}else if (S == 2){
            			string s = "P1 00-S1,i";
            			string ss = to_string(j-1);
            			string s0 = "S1";
            			string I = to_string(j-1);
            			IfNotPresent(P1,s0);
            			P1.push_back(I);
            			my_mapP1.insert(std::make_pair(s0, j-1));
            			string sss = s + ss;
            			if (FOUND(P1,"6","7","0")){
            				counterP2 --;
            		
            				output_file << sss << " " << "(mill = S0i6, S0i7, S0i0) P2 losses cow (S0,i6) | "<<counterP2<< " left"<<endl;



            			}else{
            				output_file << sss <<endl;
            			}
            			
            			
            		}else{
            			string s = "P1 00-S2,i";
            			string ss = to_string(j-1);
            			string s0 = "S3";
            			string sss = s + ss;
            			my_mapP1.insert(std::make_pair(s0, j-1));
            			output_file << sss <<endl;
            			
            		}

            	}else{
            		if (S == 1){
            			string s = "P2 00-S0,i";
            			string ss = to_string(j-1);
            			string sss = s + ss;
            			string s0 = "S0";
            			my_mapP2.insert(std::make_pair(s0, j-1));
            			output_file << sss <<endl;
            			
            		}else if (S == 2){
            			string s = "P2 00-S1,i";
            			string ss = to_string(j-1);
            			string sss = s + ss;
            			string s0 = "S1";
            			my_mapP2.insert(std::make_pair(s0, j-1));
            			output_file << sss <<endl;
            			
            		}else{
            			string s = "P2 00-S2,i";
            			string ss = to_string(j-1);
            			string sss = s + ss;
            			string s0 = "S3";
            			my_mapP2.insert(std::make_pair(s0, j-1));
            			output_file << sss <<endl;
            			
            		}

            	}
		  

            }		
        }
        if(player_piece == 1){
        	player_piece = 2;
        }else{
        	player_piece = 1;
        }
        display_board(board);
    }output_file <<endl;
    output_file<<"P1 Wins"<<endl;
    output_file<<endl;
             

}

