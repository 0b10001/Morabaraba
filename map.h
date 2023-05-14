#include <iostream>
#include <map>

int main() {
    // Create an empty map
    std::map<std::string, int> my_map;

    // Insert key-value pairs
    my_map.insert(std::make_pair("apple", 5));
    my_map.insert(std::make_pair("banana", 3));
    my_map.insert(std::make_pair("orange", 7));

    // Access values using keys
    std::cout << "The value of 'apple' is " << my_map["apple"] << std::endl;

    // Iterate over key-value pairs
    for (auto const& [key, value] : my_map) {
        std::cout << "The value of '" << key << "' is " << value << std::endl;
    }

    // Check if a key exists in the map
    if (my_map.count("banana") > 0) {
        std::cout << "The key 'banana' exists in the map." << std::endl;
    }

    return 0;
}

	if(key == "S0"){
            						if(isCowInMill(10,value, board)){
            						
            							output_file << sss << " " << "(mill = S0i6, S0i7, S0i0) P2 losses cow "<<"("<<key<<","<<value<<")"<<" | "<<counterP2<< " left"<<endl;
            							board[0][value] =0;
            							break;
            						}
            					}else if(key == "S1"){
            						if(isCowInMill(11,value, board)){
            						
            							output_file << sss << " " << "(mill = S0i6, S0i7, S0i0) P2 losses cow "<<"("<<key<<","<<value<<")"<<" | "<<counterP2<< " left"<<endl;
            							board[0][value] = 0;
            							break;
            						}
            					}
            					else{
            						if(isCowInMill(12,value, board)){
            						
            							output_file << sss << " " << "(mill = S0i6, S0i7, S0i0) P2 losses cow "<<"("<<key<<","<<value<<")"<<" | "<<counterP2<< " left"<<endl;
            							board[0][value] = 0;
            							break;
            						}
            						
            					}
						

