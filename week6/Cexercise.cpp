#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
int triangular(int n){
    if(n<=1){ return n;}
    return n + triangular(n-1);
}
int main() {
    int count;
    cin>>count;
    int valor=triangular(count);
    cout<<valor;
    return 0;
}