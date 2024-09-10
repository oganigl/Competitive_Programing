#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
int fibonacci(int n){
    if(n<=1){ return n;}
    return fibonacci(n-1) +fibonacci(n-2);
}
int main() {
    int count;
    cin>>count;
    int valor=fibonacci(count);
    cout<<valor;
    return 0;
}