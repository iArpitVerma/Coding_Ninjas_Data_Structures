#include <iostream>
#include<climits>
using namespace std;
// Brute Force
int minCount(int n){
    if(n<=0){
        return 0;
    }

    int res = INT_MAX;
    for(int i=1;i*i<=n;i++){
        int ans = minCount(n - i*i);
        res = min(res,ans); 
    }
    return 1+res;
}

// Memoization
int helper(int n, int* arr){
    if(arr[n] != -1){
        return arr[n];
    }
    
    int res = INT_MAX;
    for(int i=1;i<=n;i++){
        int ans = helper(n-i*i,arr);
        res = min(res,ans);
    }
    arr[n] = 1 + res;
    return arr[n];
}
int minCount1(int n){
    int* arr = new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i] = -1;
    }
    return helper(n,arr);
}

// Dynamic Programmming
int minCount2(int n){
    if(n<=0){
        return 0;
    }

    int* arr = new int[n+1];
    arr[0] = 0;
    for(int i=1;i<=n;i++){
        int res = INT_MAX;
        for(int j=1;j*j<=i;j++){
            res = min(res,arr[i-j*j]);
        }
        arr[i] = 1 + res;
    }

    return arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<minCount2(n)<<endl;
}