#include <iostream>
using namespace std;
// Brute Force O(3^n)
int ways(int n){
    if(n==0 || n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }

    return ways(n-1) + ways(n-2) + ways(n-3);
}

// Memoization
long helper(int n, long* arr){
    if(arr[n] != -1){
        return arr[n];
    }

    arr[n] = helper(n-1,arr) + helper(n-2,arr) + helper(n-3,arr);
    return arr[n];
}
long ways1(int n){
    long* arr = new long[n+1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++){
        arr[i] = -1;
    }
    return helper(n,arr);
}

// DP - O(n)
long ways2(int n){
    long* arr = new long[n+1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3;i<=n;i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<ways2(n)<<endl;
}