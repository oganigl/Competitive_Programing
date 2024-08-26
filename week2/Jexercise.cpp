#include <iostream>
#include <iomanip>
#include <cmath>
int  main(int argc, const char** argv) {
    long unsigned int gold_coins;
    double result;
    std::cin>>gold_coins;
    result=log(gold_coins)/log(2);
    std::cout<<std::setprecision(10)<<result;
    return 0;
}