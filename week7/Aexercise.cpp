#include <iostream>
#include <stack>
#include <string>

int main(){
    int sentences;
    std::cin>>sentences;
    std::cin.ignore();
    std::stack<std::string> books;
    std::string line,book;
    for(int i=0;i<sentences;i++){
        std::getline(std::cin,line);
        if(line[0]=='R'){
            books.pop();
        }
        else{
           size_t pos = line.find(' ');
           line.erase(0,pos+1);
           books.push(line);
        }
    }
    while(!books.empty()){
        book=books.top();
        books.pop();
        std::cout<<book<<std::endl;
    }
}