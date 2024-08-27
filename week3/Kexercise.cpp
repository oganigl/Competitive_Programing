#include <iostream>
#include <sstream>
#include <string>

int main(int argc, const char** argv) {
    std::string solution,first_line,second_line;
    bool exist=false;
    int cases;
    int number,favorite_color;
    int color;
    std::cin>>cases;
    std::cin.ignore();
    while(cases--){
        std::getline(std::cin, first_line);  
        std::istringstream iss(first_line);
        iss>>number;
        iss>>favorite_color;
        std::getline(std::cin, second_line);  
        std::istringstream iss2(second_line);
        exist=false;
        for (size_t i = 0; i < number; i++)
        {
            iss2>>color;
            if(color==favorite_color){
                solution+="YES\n";
                exist=true;
                break;
            }
        }
        if(!exist){
            solution+="NO\n";
        }
    }
    std::cout<<solution;
    return 0;
}