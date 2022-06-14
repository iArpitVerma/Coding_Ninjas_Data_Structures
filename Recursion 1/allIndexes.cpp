#include <iostream>
using namespace std;
void input(int* arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void printIndexArray(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int allIndex(int* arr1, int * arr2 ,int n,int x,int count=0,int index =0){
    if(n==0){
        return count;
    }
    if(arr1[0] == x){
        arr2[count++] = index;
    }
    allIndex(arr1+1,arr2,n-1,x,count,index+1);
}
int main(){
    int n,x;
    cin>>n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    input(arr1,n);
    cin>>x;
    int count = allIndex(arr1,arr2,n,x);
    cout<<count<<endl;
    printIndexArray(arr2,count);
}