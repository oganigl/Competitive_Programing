#include <iostream>
#include <string>
#include <map>

int main(){
    int number_drinks,drink,most_popular,value_max=0;
    std::cin>>number_drinks;
    std::map<int,int> drinks;
    for(int i=0;i<number_drinks;i++){
        std::cin>>drink;
        if(drinks.find(drink)!=drinks.end()){ 
            drinks[drink]+=1;
        }
        else{
            drinks[drink]=1;
        }
    }
    for(const auto& elem : drinks){
        if(elem.second>value_max){
            most_popular=elem.first;
            value_max=elem.second;
        }
    }
    std::cout<<most_popular<<std::endl;
    return 0;
}