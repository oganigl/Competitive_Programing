#include <iostream>
#include <vector>
void addEdge(std::vector<std::vector<int>> &graphs,int i,int j);
int main(){
    int n,m,X,Y,a,b;
    std::cin>>n>>m>>X>>Y;
    std::vector<std::vector<int>> graphs(n);
    for(int i=0;i<m;i++){
        std::cin>>a>>b;
        addEdge(graphs,a,b);
    }
    for (size_t i = 0; i < graphs.size(); i++)
    {
        std::cout<<"eLEM: "<<i<<"Conecta con:";
        for (size_t j = 0; j < graphs[i].size(); i++)
        {
            std::cout<<graphs[i][j]<<"->";
        }
        std::cout<<std::endl;
    }
    
}
void addEdge(std::vector<std::vector<int>> &graphs,int i,int j){
    graphs[i].push_back(j);
    graphs[j].push_back(i);
}