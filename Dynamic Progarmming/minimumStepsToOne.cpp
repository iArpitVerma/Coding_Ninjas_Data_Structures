#include <iostream>
#include<climits>
using namespace std;
// Brute Force
int minSteps(int n){
    if(n == 1){
        return 0;
    }
    int x = INT_MAX, y= INT_MAX;
    if( n%3 == 0 ){
        x = minSteps(n/3);
    }
    if(n%2 == 0){
        y = minSteps(n/2);
    }
    int z = minSteps(n-1);
    int ans =  min(x,(y,z));
    return 1 + ans;
}

// Memoization
int helper(int n, int * arr){
    if(n<=1){
        return 0;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    int x = helper(n-1,arr);
    int y = INT_MAX, z = INT_MAX;
    if(n%2 == 0){
        y = helper(n/2,arr);
    } 
    if(n%3==0){
        z = helper(n/3,arr);
    }

    int ans = min(x,(y,z)) + 1;
    arr[n] = ans;
    return arr[n];
}
int minSteps1(int n){
    int* arr =new int[n+1];
    return helper(n,arr);
}

// Dynamic Programming
int minSteps2(int n){
    int * arr = new int[n+1];
    if(n<=1){
        return 0;
    }    

    for(int i=0;i<n+1;i++){
        if(i<=1){
            arr[i] = 0;
            continue;
        }

        int x = arr[i-1];
        int y = INT_MAX, z = INT_MAX;
        if(i%2 == 0){
            y = arr[i/2];
        }
        if(i%3 == 0){
            z = arr[i/3];
        }

        int ans = 1 + min(x,(y,z));
        arr[i] = ans; 
    }

    return arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<minSteps2(n)<<endl;
}