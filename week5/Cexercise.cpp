#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

bool find_book(vector<int> &library, int book){
    int begin = 0;
    int end = library.size() - 1;
    
    while (begin <= end) {
        int middle = begin + (end - begin) / 2;
        
        if (library[middle] == book) {
            return true; 
        }
        if (library[middle] > book) {
            end = middle - 1;
        } else {
            begin = middle + 1; 
        }
    }
    return false; 
}

int main() {
    int number_of_books,book,consults;
    vector<int> library;
    cin>>number_of_books;
    cin.ignore();
    for(int i=0;i<number_of_books;i++){
        cin>>book;
        library.push_back(book);
    }
    sort(library.begin(),library.end());
    cin.ignore();
    cin>>consults;
    for(int i=0;i<consults;i++){
        cin>>book;
        if(find_book(library,book)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}