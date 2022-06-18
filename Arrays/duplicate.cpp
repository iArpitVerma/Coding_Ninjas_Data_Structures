#include<bits/stdc++.h>
using namespace std;
int duplicate(int * arr, int n){
    int actualSum = 0;
    for(int i=0;i<n;i++){
        actualSum = actualSum + arr[i];
    }
    // sum of n elements = ((n)*(n+1))/2
    // desiredNo. = actualSum - sum of n-2 elements
    return actualSum - ((n-2)*(n-1))/2;

}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int * arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<duplicate(arr,n)<<endl;
        delete []arr;
    }

}