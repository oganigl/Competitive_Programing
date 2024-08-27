#include <iostream>
#include <sstream>
#include <string>

int main(int argc, const char** argv) {
    std::string input;
    std::string last_line;
    while(std::getline(std::cin, input)){
        last_line=input;
    }
    std::cout<<last_line;
    return 0;
}