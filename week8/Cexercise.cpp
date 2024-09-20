#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
void join_set(std::vector<std::unordered_set<int>>& connections,int from,int to){
    for(const auto& elem : connections[from]){
        connections[to].insert(elem);
    }
    connections.erase(connections.begin()+ from);
}
int main(){
    int destinations;
    char not_important;
    bool connected=true;
    bool find;
    int from,to,i,find_to,find_from;
    std::cin>>destinations;
    std::vector<std::unordered_set<int>> connections;
    while(connected){
        std::cin>>not_important>>from>>to;
        find_to=find_from=-1;
        find=false;
        for(i=0;i<connections.size();i++){
            if(connections[i].find(from)!=connections[i].end() && connections[i].find(to)!=connections[i].end()){ //Both are in the same path we finished
                connected=false;
                break;
            }
            else if(connections[i].find(from)!=connections[i].end()){ 
                if(find_from==-1){
                    connections[i].insert(from);
                    connections[i].insert(to);
                    find_from=find_to=i;
                    find=true;
                }else{
                    join_set(connections,i,find_from);
                }   
            }
            else if(connections[i].find(to)!=connections[i].end()){
                if(find_to==-1){
                    connections[i].insert(from);
                    connections[i].insert(to);
                    find_to=find_from=i;
                    find=true;
                }else{
                    join_set(connections,i,find_to);
                }
            }
        }
        if(i==connections.size() && find==false){
            std::unordered_set<int> new_unordered;
            new_unordered.insert(from);
            new_unordered.insert(to);
            connections.push_back(new_unordered);
        }
        if(connected){
            std::cout<<"SI"<<std::endl;
        }
        else{
            std::cout<<"NO"<<std::endl;
        }
    }
}