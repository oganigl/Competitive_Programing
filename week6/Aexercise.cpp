#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
void countdown(int count){
    if(!count){ return; }
 cout<<count<<endl;
 countdown(count-1);
}
int main() {
    int count;
    cin>>count;
    countdown(count);
    return 0;
}