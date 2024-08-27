#include <iostream>
#include <sstream>
#include <string>

int main(int argc, const char** argv) {
    std::string input;
    std::getline(std::cin, input);  
    std::istringstream iss(input);
    int num;
    long long int amass=0;
    while (iss >> num) {  
        amass+=num;
        std::cout<<amass<<" ";
    }
    return 0;
}
