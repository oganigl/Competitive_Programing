#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;


int main() {
    int n;
    long int number;
    string word;
    cin>>n;
   vector<pair<long int,string>> coffee;
    for(int i=0;i<n;i++){
        cin>>number;
        cin>>word;
        cin.ignore();
        coffee.push_back({number,word});
    }
    sort(coffee.begin(),coffee.end());
    for(auto pair : coffee){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    return 0;
}