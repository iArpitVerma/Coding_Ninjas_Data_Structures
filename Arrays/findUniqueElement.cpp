#include <iostream>
using namespace std;
int uniqueElement(int * arr,int n){
    // Brute Force
    for(int i=0;i<n;i++){
        int uniqueElement = arr[i];
        for(int j=0;j<n;j++){
            if( arr[i] == arr[j] && i!=j){
                break;
            }
            else if(arr[i] != arr[j] && j==n-1){
                return uniqueElement;
            }
        }
    }
}

int uniqueElement1(int * arr,int n){
    // Optimized Solution O(n)
    int ans =0;
    for(int i=0;i<n;i++){
        ans = ans ^ arr[i];
    }
    return ans;
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
        cout<<uniqueElement1(arr,n)<<endl;
        delete []arr;
    }
}