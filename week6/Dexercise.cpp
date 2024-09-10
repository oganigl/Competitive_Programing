#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
void printAscending(int n,int ini){
    if(ini>n){return;}
    for(int i=0;i<ini;i++){
        cout<<"#";
    }
    cout<<endl;
    printAscending(n,ini+1);
}
void printDescending(int n){
    if(!n){ return; }
    for(int i=0;i<n;i++){
        cout<<"#";
    }
    cout<<endl;
    printDescending(n-1);
}
void arrow(int n){
    printAscending(n,1);
    printDescending(n-1);
}
int main() {
    int count;
    cin>>count;
    arrow(count);
    return 0;
}