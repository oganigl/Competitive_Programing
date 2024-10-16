#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
struct connection{
    int square;
    int distance;
};
struct checkpoint{
    int square;
    int time;
};
void every_possible_path(int time,int speed,int start,std::vector<std::vector<connection>>& city,std::vector<std::unordered_set<int>>& solution,int runner){
    std::queue<checkpoint> paths;
    paths.push(checkpoint{start,time}); 
    std::unordered_map<int,bool> visited_nodes;
    if(!runner){
        solution[start].insert(time);
    }
    else{
        for(int i=1;i<visited_nodes.size();i++){
            visited_nodes[i]=false;
        }
    }
    checkpoint last_square;
    int new_time,square_time;
    
    while(!paths.empty()){
        last_square=paths.front();
        paths.pop();
        new_time=last_square.time;
        for(const auto& value : city[last_square.square]){
            square_time=new_time-(value.distance/speed);
            if(!runner){
                    if(square_time>=0){
                        paths.push(checkpoint{value.square,square_time});
                        solution[value.square].insert(square_time);
                    }else{
                        solution[last_square.square].insert(0);
                }
            }else{
                if(square_time>=0){
                    paths.push(checkpoint{value.square,square_time});
                    if (visited_nodes[value.square]==false && solution[value.square].find(square_time) != solution[value.square].end()) {
                        visited_nodes[value.square]=true;
                    }
                }
            }
        }
    }
    if(runner){
        std::cout<<visited_nodes.size()<<std::endl;
        for (auto it=visited_nodes.begin(); it!=visited_nodes.end(); it++) {
            std::cout << it->first <<" ";
        }
    }
}
int main(){
    int number_squares,time,speed_a,speed_b,a_start,b_start,from,to,distance;
    std::cin>>number_squares>>time>>speed_a>>speed_b;
    std::cin>>a_start>>b_start;
    std::vector<std::vector<connection>> city(number_squares+1);
    for(int i=0;i<number_squares-1;i++){
        std::cin>>from>>to>>distance;
        city[from].push_back(connection{to,distance});
        city[to].push_back(connection{from,distance});
    }
    std::vector<std::unordered_set<int>> solution_a(number_squares+1);
    every_possible_path(time,speed_a,a_start,city,solution_a,0);
    every_possible_path(time,speed_b,b_start,city,solution_a,1);
    return 0;
}