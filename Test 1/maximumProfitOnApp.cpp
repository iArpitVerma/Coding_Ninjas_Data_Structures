#include <bits/stdc++.h>
using namespace std;
int maximumProfit(int * arr, int n){
    sort(arr, arr+n);
    int maxProfit = 0;
    for(int i=0;i<n;i++){
        if(maxProfit < arr[i]*(n-i)){
            maxProfit = arr[i]*(n-i);
        }
    }
    return maxProfit;
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maximumProfit(arr,n)<<endl;
    delete []arr;
}