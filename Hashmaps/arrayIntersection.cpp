#include <iostream>
#include<unordered_map>
using namespace std;
void arrayIntersection(int* arr1, int *arr2, int n, int m){
    unordered_map<int,int> map;
    for(int i=0;i<m;i++){
        map[arr2[i]]++;
    } 

    for(int i=0;i<n;i++){
        if(map[arr1[i]] > 0){
            cout<<arr1[i]<<" ";
            map[arr1[i]]--;
        }
    }   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        int arr1[n];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        cin>>m;
        int arr2[m];
        for(int i=0;i<m;i++){
            cin>>arr2[i];
        }
        arrayIntersection(arr1,arr2,n,m);
    }
}