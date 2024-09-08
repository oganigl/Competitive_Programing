#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


int main() {
   int rows,columns,number;
   cin>>rows;
   cin>>columns;
   cin.ignore();
   char frame[rows][columns];
   bool original=true;
   string line;
   for(int i=0;i<rows;i++){
        getline(cin,line);
        for(int j=0;j<columns;j++){
            frame[i][j]=line[j];
        }
   }

   for(int i=1;i<rows && original;i++){
        for(int j=1;j<columns;j++){
            if(frame[i][j]==frame[i-1][j]&& frame[i][j] && frame[i][j]==frame[i-1][j-1] && frame[i][j]==frame[i][j-1]){
                original=false;
                break;
            }
        }
    }
    if(original){
        cout<<"ORIGINAL";
    }
    else{
        cout<<"NO ORIGINAL";
    }
   return 0;
}