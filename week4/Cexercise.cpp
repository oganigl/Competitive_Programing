#include <iostream>
#include <string>
using namespace std;

void alternate_array(int n){
   int arr1[n];
   int arr2[n];
   int numero;
for(int i=0;i<n;i++){
    cin>>numero;
    i%2==0 ? (arr1[i]=numero) : (arr2[i]=numero);
}
for(int i=0;i<n;i++){
    cin>>numero;
    i%2!=0 ? (arr1[i]=numero) : (arr2[i]=numero);
}
for(int arr : arr1){
    cout<<arr<<" ";
}
cout<<endl;
for (int arr : arr2){
    cout<<arr<<" ";
}
}

int main() {
    int number;
    cin>>number;
    cin.ignore();
    alternate_array(number);
    return 0;
}