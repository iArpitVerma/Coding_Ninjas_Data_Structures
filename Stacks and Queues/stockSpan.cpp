#include <iostream>
using namespace std;
#include<stack>

// Brute Force - O(n2)
int* stockSpan(int n){
    stack<int> s1,s2;
    int a;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>a;
        s1.push(a);
    }
    for(int i=0;i<n;i++){
        a = s1.top();
        s1.pop();
        int count = 1;
        for(int j=0;j<n-i-1;j++){
            if(a>s1.top()){
                s2.push(s1.top());
                s1.pop();
                count++;
            }else{
                break;
            }
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        arr[n-i-1] = count;
    }
    return arr;
}


int main(){
    int n;
    cin>>n;
    int* arr = stockSpan(n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}