#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;


int main() {
   int cases,rows,columns;
   float epsilon,number;
   cin>>cases;
   vector<vector<vector<float>>> matrices; 
   for(int i=0;i<cases;i++){
        cin>>rows;
        cin>>columns;
        cin>>epsilon;
        vector<vector<float>> table(rows,vector<float>(columns));  
        for(int j=0;j<rows;j++){
            for(int k=0;k<columns;k++){
                cin>>number;
                number<=epsilon ? table[j][k]=0.0f : table[j][k]=number;
            }
        }
        matrices.push_back(table);
    }
    for(auto table : matrices){
        for(auto line : table){
            for(float number :line){
                cout<<setprecision(6)<<fixed<<number<<" ";
            }
            cout<<endl;
        }
    }
   return 0;
}