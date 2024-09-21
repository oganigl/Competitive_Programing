#include<iostream>
#include <unordered_set>
#include <array>
#include <string>
int main(){
    std::string line,piece;
    std::getline(std::cin,line);
    int substring;
    std::cin>>substring;
    std::unordered_set<std::string> uniques;
    for(int i=0;i<line.size()-substring+1;i++){
        piece=line.substr(i,substring);
        if(piece.size()<substring){
            break;
        }
        uniques.insert(piece);
    }
    std::cout<<uniques.size();
    return 0;
}