#include <iostream>
using namespace std;
void input(int * arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int firstIndex(int* arr,int n,int x,int i=0){
    if(n==0){
        return -1;
    }
    
    if(arr[0]==x){
        return i;
    }
    firstIndex(arr+1,n-1,x,i+1);
}
int main(){
    int n,x;
    cin>>n;
    int* arr = new int[n];
    input(arr,n);
    cin>>x;
    cout<<firstIndex(arr,n,x)<<endl;
    delete [] arr;
}