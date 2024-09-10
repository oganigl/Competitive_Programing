#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
void swap(vector<int>& array,int pos1,int pos2){
    int aux=array[pos1];
    array[pos1]=array[pos2];
    array[pos2]=aux;
}
void bubble_sort(vector<int> &array, int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(array[j]>array[j+1]){
                swap(array,j,j+1);
            }
        }
    }
}
void insertion_sort(vector<int> &array, int size){
    for(int i=1;i<size;i++){
        int key=array[i];
        int j=i-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j--;
        }       
        array[j+1]=key; 
    }
}
void selection_sort(vector<int> &array, int size){
    int min_valor,pos_min;
    for(int i=0;i<size-1;i++){
        min_valor=array[i];
        pos_min=i;
        for(int j=i;j<size;j++){
            if(array[j]<min_valor){
                min_valor=array[j];
                pos_min=j;
            }
        }
        swap(array,i,pos_min);
    }
}
void merge(vector<int> &array,vector<int> &l1,vector<int> &l2){
    int i1=0,i2=0;
    for(int i=0;i<array.size();i++){
        if(l1.size()==i1){
            array[i]=l2[i2++];
        }
        else if(l2.size()==i2){
            array[i]=l1[i1++];
        }else if(l2[i2] < l1[i1]){
            array[i]=l2[i2++];
        }else{
            array[i]=l1[i1++];
        }
    }
}
void merge_sort(vector<int> &array, int size){
    if(size==1){
        return;
    }
    int mid=(array.size()/2)-1;
    vector<int> l1(array.begin(),array.begin()+mid+1);
    vector<int> l2(array.begin()+mid+1,array.begin()+array.size());
    merge_sort(l1,l1.size());
    merge_sort(l2,l2.size());
    merge(array,l1,l2);
}
void quick_sort(vector<int> &array,int begin,int end){
    if(begin>=end){
        return;
    }
    int pivot=array[end];
    int partition_index=begin;
    for(int i=begin;i<end;i++){
        if(array[i] < pivot){
            swap(array,i,partition_index);
            partition_index++;
        }
    }
    swap(array,partition_index,end);
    quick_sort(array,begin,partition_index-1);
    quick_sort(array,partition_index+1,end);
}
void pigeonhole_sort(vector<int> &array){
    if(array.empty()){
        return;
    }
    int min_val=array[0];
    int max_val=array[0];
    for(int i=1;i<array.size();i++){
        min_val=min(array[i],min_val);
        max_val=max(array[i],max_val);
    }
    vector<int> aux(max_val-min_val+1,0);
    for(int i=0;i<array.size();i++){
        aux[array[i]-min_val]++;
    }
    int index=0;
    for(int i=0;i<aux.size();i++){
        while(aux[i]-- > 0){
            array[index++]=i+min_val;
        }
    }
}
void countSort(vector<int>& array,int n,int exp){
    int output[n],i,count[10]={0};
    for(int i=0;i<n;i++){
        count[array[i]/exp %10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[array[i]/exp %10]-1]=array[i];
        count[(array[i] /exp %10)]--;
    }
    for(int i=0;i<n;i++){
        array[i]=output[i];
    }
}
void radix_sort(vector<int> &array){
    if(array.empty()){ return; }
    int max_val=array[0];
    for(int i=0;i<array.size();i++){
        max_val=max(array[i],max_val);
    }
    int exp;
    for(exp=1;max_val/exp>0;exp*=10){
        countSort(array,array.size(),exp);
    }
}
int main() {
    int size,number;
    cin>>size;
    vector<int> array(size);
    for(int i=0;i<size;i++){
        cin>>number;
        array[i]=number;
    }
    radix_sort(array);
    for(const auto & num : array){
        cout<<num<<" ";
    }
    return 0;
}