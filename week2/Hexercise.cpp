#include <iostream>
#include <iomanip>
#include <cmath>
int  main(int argc, const char** argv) {
    double time;
    double final_quantity;
    std::cin>>final_quantity;
    time=std::log(final_quantity);
    std::cout<<std::setprecision(17)<<time;
    return 0;
}