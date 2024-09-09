#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

void calculate_difference(int n){
    vector<long int> L_hooks(n);
    long int number,difference=LONG_MAX;
    for(int i=0; i<n;i++){
        cin>>number;
        L_hooks[i]=number;
    }
    sort(L_hooks.begin(),L_hooks.end());
    for(int i=0; i<n;i++){
        
            difference = min(difference,abs(L_hooks[i] - L_hooks[i+1]));
    }
    std::cout<<difference;
}

int main() {
    int quantity;
    cin>>quantity;
    cin.ignore();
    calculate_difference(quantity);
    return 0;
}