#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
int main(){
    std::priority_queue<std::pair<uint64_t,uint64_t>> things_to_do;
    uint32_t number_of_lines;
    std::cin>>number_of_lines;
    char task;
    uint64_t priority,id;
    std::unordered_set<uint64_t> used_ids;
    for(uint32_t i=0;i<number_of_lines;i++){
        std::cin>>task;
        switch (task){
            case '+':
                std::cin>>priority>>id;
                things_to_do.push(std::make_pair(priority,id));
                break;
            case '-':
                std::cin>>id;
                used_ids.push_back(id);
                std::cout<<id<<std::endl;
                break;
            case '!':
                do{
                id=things_to_do.top().second;
                things_to_do.pop();
                }while(std::find(used_ids.begin(),used_ids.end(),id)!=used_ids.end());
                std::cout<<id<<std::endl;
                break;
        }
    } 
    return 0;
}