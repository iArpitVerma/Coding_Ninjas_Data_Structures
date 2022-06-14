#include <iostream>
using namespace std;
void input(int * arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int lastIndex(int * arr,int n,int x){
    if(n==0){
        return -1;
    }
    int ans = lastIndex(arr+1,n-1,x);
    if(ans != -1){
        return ans+1;
    }
    if(arr[0] == x){
        return 0;
    }
    return -1;
    
}
int main(){
    int n,x;
    cin>>n;
    int* arr = new int[n];
    input(arr,n);
    cin>>x;
    cout<<lastIndex(arr,n,x)<<endl;
    delete [] arr;
}