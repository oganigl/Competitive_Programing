#include <iostream>
#include <string>
#include <vector>
using namespace std;
void complete_table(vector<vector<char>> &matrix,int x,int y,int length,int width){
    for(int i=0;i<width;i++){
        matrix[x][i]='#';
    }
    for(int i=0;i<length;i++){
        matrix[i][y]='#';
    }
}
void solve_table(int length,int width){
   std::vector<std::vector<char>> matrix(length, std::vector<char>(width, '.'));
   string line;
    for(int i=0;i<length;i++){
        getline(cin,line);
        for(int j=0;j<width;j++){
            if(line[j]=='#'){
                complete_table(matrix,i,j,length,width);
            }
        }
    }
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

int main() {
    int width,length;
    cin>>length;
    cin>>width;
    cin.ignore();
    solve_table(length,width);
    return 0;
}