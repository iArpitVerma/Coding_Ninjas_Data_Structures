#include <iostream>
using namespace std;
// Brute Force
int maxSum(int* arr, int i, int n){
    if(i>=n){
        return 0;
    }

    int a = arr[i] + maxSum(arr,i+2,n);
    int b = maxSum(arr,i+1,n);

    return max(a,b);
}

// DP
int maxSum1(int* arr, int n){
    int* output = new int[n];
    output[0] = arr[0];
    output[1] = max(arr[0],arr[1]);

    for(int i=2;i<n;i++){
        output[i] = max(arr[i] + output[i-2], output[i-1]);
    }

    return output[n-1];
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxSum(arr,0,n)<<endl;
    cout<<maxSum1(arr,n)<<endl;
}