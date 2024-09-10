#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;


int main() {
    int participants,problems_solved,punishment;
    cin>>participants;
   vector<pair<int,int>> contestant(participants);
    for(int i=0;i<participants;i++){
        cin>>problems_solved;
        cin>>punishment;
        contestant[i]=make_pair(problems_solved,punishment);
        
    }
    sort(contestant.begin(), contestant.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        if(a.first != b.first)
            return a.first > b.first; 
        return a.second < b.second; 
    });
    for(const auto &pair : contestant){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    return 0;
}