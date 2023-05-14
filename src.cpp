#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "algo1.h"
#include "test.h"
#include <algorithm>

using namespace std;


int main() {

    string line;
    ifstream input_file("input.txt");
    //ofstream output_file("morabarabaResults.txt", ios::app); 

    if (input_file.is_open()) {
        // read lines from input file
        while (getline(input_file, line)) {
            // process the line here
            // ...
            int integer = stoi(line);

            myFunction (integer);

          
        }
        
        input_file.close();

    }
    
    return 0;
}

