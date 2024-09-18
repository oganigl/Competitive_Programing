#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;


const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValidMove(int x, int y, int width, int height, vector<vector<char>>& maze) {
    return x >= 0 && x < height && y >= 0 && y < width && (maze[x][y] == '.' || maze[x][y] == 'S');
}
void min_row(vector<vector<int>>& chair,int row,int pos,int& minim,int& pos_min){
    if(chair[row].size() <=pos){
        return;
    }
    if(minim>chair[row][pos]){
            minim=chair[row][pos];
            pos_min=pos;
    }
     min_row(chair,row,pos+1,minim,pos_min);
}
void max_column(vector<vector<int>>& chair,int pos,int column,int& maxim,int& pos_max){
    if(pos>=chair.size()){
        return;
    }
    if(maxim<chair[pos][column]){
        maxim=chair[pos][column];
        pos_max=pos;
    }
    max_column(chair,pos+1,column,maxim,pos_max);
}
pair<int,int> find_chair_point(vector<vector<int>>& chair,int n,int m){
    int minim,pos_min,maxim,pos_max;
    for(int i=0;i<n;i++){
        minim=chair[i][0];
        pos_min=0;
        min_row(chair,i,1,minim,pos_min);
        maxim=chair[0][pos_min];
        pos_max=0;
        max_column(chair,1,pos_min,maxim,pos_max);
        if(maxim==minim){
            return {pos_max,pos_min};
        }
    }
    return {-1,-1};
}
int main() {
    int cases,n,m,number;
   vector<pair<int,int>> solution;
    cin>>cases;
    for(int i=0;i<cases;i++){
        cin>>n>>m;
        vector<vector<int>> chair(n, vector<int>(m));
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>number;
                chair[j][k]=number;
            }
        }
        solution.push_back(find_chair_point(chair,n,m));
    }
    for(const auto& sol :solution){
        std::cout<<sol.first<<" "<<sol.second<<std::endl;
    }
}
