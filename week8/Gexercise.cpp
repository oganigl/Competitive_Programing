#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>

void depth_first_search(int start_square, std::vector<std::vector<int>> city,int number_streets,std::vector<std::vector<bool>>& visited_streets){
    std::stack<int> path;
    path.push(start_square);
    int node_to_explore;
    std::vector<int> closed_list;
    bool dead_node,first=true;
    while(!path.empty()){
        node_to_explore=path.top();
        if(node_to_explore==start_square && closed_list.size()==number_streets){
            break;
        }
        path.pop();
        dead_node=true;
          if(first){
            first=false;
        }else{
            visited_streets[node_to_explore][closed_list.back()]=visited_streets[closed_list.back()][node_to_explore]=true;
        }
        closed_list.push_back(node_to_explore);
        for(const auto& node :city[node_to_explore]){
            if(visited_streets[node][node_to_explore]==false){
                dead_node=false;
                path.push(node);
            }
        }
        if(dead_node==true){
            closed_list.pop_back();
            int previous=closed_list.back();
            visited_streets[previous][node_to_explore]=visited_streets[previous][node_to_explore]=false;
        }
    }
    if(closed_list.size()==number_streets){
        for(const auto& node : closed_list){
            std::cout<<node<<std::endl;
        }
        std::cout<<start_square;
    }else{
        int no_path=-1;
        std::cout<<no_path;
    }
    

}
int main(){
    int number_streets,number_squares,start_square,from,to;
    std::cin>>number_squares>>number_streets>>start_square;
    std::vector<std::vector<int>> city(number_squares+1);
    std::vector<std::vector<bool>> visited_streets(number_squares+1,std::vector<bool>(number_squares+1,false));
    std::pair<int,int> street;
    for(int i=0;i<number_streets;i++){
        std::cin>>from>>to;
        city[from].push_back(to);
        city[to].push_back(from);        
    }
    depth_first_search(start_square,city,number_streets,visited_streets);
    return 0;
}