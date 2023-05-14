#ifndef MYHEADER_H
#define MYHEADER_H

#include <cstdlib>
#include <ctime>
#include <random>

int randomNumber(int N){

    // Set seed for random number generator
    //std::srand(std::time(nullptr));
    
    // Generate random number between 1 and 100
    //int random_number = std::rand() % N;
    
    // Print the random number
    //return random_number;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1,N);
    return dist(rd);
}

#endif
