#include <iostream>
#include <vector>
#include <string>
#include <sstream>
int main(){
    int nodes,edges,a,b,new_connections=0;
    std::cin>>nodes>>edges;    
    std::string line;
    std::cin.ignore();
    std::vector<std::string> solution;
    bool matrix[nodes+1][nodes+1]={false};
    for(;edges>0;edges--){
        std::cin>>a>>b;
       matrix[a][b]=matrix[b][a]=true;
    }
    for(int i=1;i<nodes+1;i++){
        for(int j=i+1;j<nodes+1;j++){
            if(!matrix[i][j]){
                line=std::to_string(i)+" "+std::to_string(j)+"\n";
                solution.push_back(line);
            }
        }
    }
    if(!solution.empty()){
        std::cout<<solution.size()<<std::endl;
        for(const auto& sol : solution){
            std::cout<<sol;
        }
    }else{
        std::cout<<"0";
    }
    return 0;

}