#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


int main() {
   int cases;
   cin>>cases;
   cin.ignore();
   string line;
   vector<vector<string>> solution(cases, vector<string>(8));
   for(int i=0;i<cases;i++){
    for(int j=0;j<8;j++){
        getline(cin,line);
        for(int k=0;k<8;k++){
            if(j%2==0){
                if((k%2==0 && line[k]=='B') || (k%2!=0 && line[k]=='W')){ //There is a mistake
                    line[k]='X';
                }
            }
            else{
                if((k%2==0 && line[k]=='W') || (k%2!=0 && line[k]=='B')){ //There is a mistake
                    line[k]='X';
                }
            }
            
        }
        solution[i][j]=line;
    }
   }
   for(int i=0;i<cases;i++){
    for(int j=0;j<8;j++){
        cout<<solution[i][j]<<endl;
    }
   }
   return 0;
}