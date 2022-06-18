#include <iostream>
using namespace std;
int arrayRotation(int* arr, int n){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            return i+1;
        }
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int * arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<arrayRotation(arr,n)<<endl;
        delete []arr;
    }  
}