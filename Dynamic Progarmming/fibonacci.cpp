#include <iostream>
using namespace std;
// Brute force 
// Time Complexity - O(2^n)
int fibonacci(int n){
    if(n<=1){
        return n;
    }

    int a = fibonacci(n-1);
    int b = fibonacci(n-2);

    return a+b;
}

// Memoization Techinque
// Time Complexity - O(n)
int helper(int n, int* arr){
    if(n<=1){
        return n;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    int a = helper(n-1,arr);
    int b = helper(n-2,arr);

    arr[n] = a + b;
    return arr[n];
}
int fibonacci_2(int n){
    int* arr = new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i] = -1;
    }
    return helper(n,arr);
}

// Dynamic Programming
// Time Complexity - O(n)
int fibonacci_3(int n){
    if(n<=1){
        return n;
    }
    int* arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<n+1;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fibonacci_3(n)<<endl;
}