#include <iostream>
#include<cmath>
using namespace std;
// Brute Force
int numberOfBalancedBTs(int h){
    if(h<=1){
        return 1;
    }

    int mod = (int)(pow(10,9)) + 7;
    int x = numberOfBalancedBTs(h-1)%mod;
    int y = numberOfBalancedBTs(h-2)%mod;
    int temp1 = (int)(((long)(x) * x )% mod);
    int temp2 = (int)((2*(long)(x) * y )% mod);

    int ans = (int)((temp1 + temp2)%mod);
    return ans;
}

// Memoization
int helper(int h, int * arr){
    if(arr[h] != -1){
        return arr[h];
    }

    int mod = (int)(pow(10,9) + 7);
    int x = helper(h-1,arr);
    int y = helper(h-2,arr);
    int temp1 = (int)(((long)(x) * x )% mod);
    int temp2 = (int)((2*(long)(x) * y )% mod);
    arr[h] = (int)((temp1 + temp2)%mod);
    return arr[h];
}
int numberOfBalancedBTs1(int h){
    int * arr = new int[h+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i<=h;i++){
        arr[i] = -1;
    }
    return helper(h,arr);
}

// DP
int numberOfBalancedBTs2(int h){
    int* arr = new int[h+1];
    arr[0]=1;
    arr[1]=1;

    int mod = (int)(pow(10,9) + 7);

    for(int i=2;i<=h;i++){
        int x = arr[i-1];
        int y = arr[i-2];
        int temp1 = (int)(((long)(x) * x )% mod);
        int temp2 = (int)((2*(long)(x) * y )% mod);
        arr[i] = (int)((temp1 + temp2)%mod);
    }
    return arr[h];
}
int main(){
    int h;
    cin>>h;
    cout<<numberOfBalancedBTs1(h)<<endl;
}