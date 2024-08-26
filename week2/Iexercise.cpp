#include <iostream>
#include <iomanip>
#include <cmath>
int  main(int argc, const char** argv) {
    long unsigned int area;
    double length;
    std::cin>>area;
    length= sqrt(area);
    std::cout<<std::setprecision(10)<<length;
    return 0;
}