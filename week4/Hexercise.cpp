#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


int main() {
   int rows,columns,number;
   long int max_sum=0;
   long int sum_vertical,sum_horizontal;
   cin>>rows;
   cin>>columns;
   cin.ignore();
   int matrix[rows][columns];
   //we add all the numbers
   for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>number;
            matrix[i][j]=number;
        }
   }
   for(int i=0;i<rows;i++){
        sum_horizontal=0;
        for(int j=0;j<columns;j++){
            sum_horizontal+=matrix[i][j];
        }
        if(sum_horizontal>max_sum){
            max_sum=sum_horizontal;
        }
   }
   for(int i=0;i<columns;i++){
        sum_vertical=0;
        for(int j=0;j<rows;j++){
            sum_vertical+=matrix[j][i];
        }
        if(sum_vertical>max_sum){
            max_sum=sum_vertical;
        }
   }
   cout<<max_sum;
   return 0;
}