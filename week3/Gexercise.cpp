#include <iostream>
#include <sstream>
#include <string>

int main(int argc, const char** argv) {
    int num;
    std::cin>>num;
    for (size_t i = 1; i <= num; i++)
    {
        if(i%3==0 && i%5==0){
            std::cout<<"FizzBuzz"<<std::endl;
        }else if(i%3==0){
            std::cout<<"Fizz"<<std::endl;
        }else if(i%5==0){
            std::cout<<"Buzz"<<std::endl;
        }else{
            std::cout<<i<<std::endl;
        }
    }
    return 0;
}
