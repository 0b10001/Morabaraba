#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;
    ifstream input_file("input.txt");
    ofstream output_file("morabarabaResults.txt", ios::app); // open output file in append mode

    if (input_file.is_open() && output_file.is_open()) {
        // read lines from input file
        while (getline(input_file, line)) {
            // process the line here
            // ...

            // write to output file with a space before each new line
            output_file << line <<endl;
            output_file << "P1" <<endl;
            output_file << "line" <<endl;
            output_file << "line" <<endl;
            output_file <<endl;
            output_file << "P1 wins" <<endl;
            output_file <<endl;
            break;
        }
        
        
        input_file.close();
        output_file.close();
    }
    else {
        cout << "Error opening files!" << endl;
    }

    return 0;
}

