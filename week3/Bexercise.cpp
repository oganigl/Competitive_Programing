#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
int  main(int argc, const char** argv) {
    long int first,second;
    float result;
    char operation;
    std::cin>>first;
    std::cin>>operation;
    std::cin>>second;
    if(operation=='+'){
        std::cout<<first+second;
    }
    if(operation=='-'){
        std::cout<<first-second;    
    }
    if(operation=='*'){
        std::cout<<first*second;
    }
    if(operation=='/'){
        if(!second){
            std::cout<<"ERROR";
        }
        else{
            result=first/static_cast<float>(second);
            std::cout<<std::fixed<<std::setprecision(2)<<result;
        }
    }
    return 0;
}