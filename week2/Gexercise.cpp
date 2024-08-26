#include <iostream>
#include <cmath>
int  main(int argc, const char** argv) {
    int water_first_day;
    int days;
    std::cin>>water_first_day;
    std::cin>>days;
    long long int result;
    result=pow(water_first_day,days);
    std::cout<<result;
    return 0;
}