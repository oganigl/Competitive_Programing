#include <iostream>
#include <vector>
#include <algorithm>
void print(const std::vector<bool>& accusations){
    std::cout<<"print"<<std::endl;
    for(const auto& elem : accusations){
        std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
}
int guilty(const std::vector<int>& accusations,int n){
    std::vector<bool> checked_before(accusations.size(),false);
    bool is_guilty=false;
    checked_before[n]=true;
    while(1){
        if(checked_before[accusations[n]]==false){
            checked_before[accusations[n]]=true;
            n=accusations[n];
           // std::cout<<"Acusado: "<<accusations[n]-1<<std::endl;
           //print(checked_before);
        }else{
            return accusations[n];
        }
    }
}

int main(){
    int students,accused,guilt;
    std::cin>>students;
    std::vector<int> accusations(students+1);
    for (size_t i = 1; i < students+1; i++)
    {
        std::cin>>accused;
        accusations[i]=accused;
    }
    for (size_t i = 1; i < students+1; i++)
    {
        guilt=guilty(accusations,i);
        std::cout/*<<std::endl<<"Guilty: "*/<<guilt<<" ";
    }
    
}