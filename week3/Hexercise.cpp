#include <iostream>
#include <sstream>
#include <string>

int main(int argc, const char** argv) {
    int quantity,num,max,min;
    std::cin>>quantity;
    std::cin>>num;
    max=num;
    min=num;
    for (size_t i = 1; i < quantity; i++)
    {
       std::cin>>num;
       if(num<min){
        min=num;
       }
       if(num>max){
        max=num;
       }
    }
    std::cout<<min<<" "<<max;
    return 0;
}
