#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string.h>
int  main(int argc, const char** argv) {
    long unsigned int number;
    std::cin>>number;
    int remainder,result;
    result=0;
    do{
        remainder=number%10;
        number=number/10;
        result+=remainder;
    }while(number);
    std::cout<<result;
    return 0;
}