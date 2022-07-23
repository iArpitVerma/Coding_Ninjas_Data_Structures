#include <iostream>
#include<unordered_map>
using namespace std;
int maxFrequencyElement(int* arr, int n){
    unordered_map<int,int> max;
    for(int i=0;i<n;i++){
        max[arr[i]]++;
    }
    int key =0,value=0;
    for(int i=0;i<n;i++){
        if(max[arr[i]] > value){
            key = arr[i];
            value = max[arr[i]];
        }
    }
    return key;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxFrequencyElement(arr,n);
}