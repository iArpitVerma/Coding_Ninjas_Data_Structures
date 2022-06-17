#include <iostream>
using namespace std;
int binarySearch(int arr[],int x,int si,int ei){
    if(si>ei){
        return -1;
    }
    int mid = (si+ei)/2;
    if(arr[mid] == x){
        return mid;
    }
    else if(arr[mid]>x){
        binarySearch(arr,x,si,mid-1);
    }
    else{
        binarySearch(arr,x,mid+1,ei);
    }
}
int main(){
    int n,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;
    cout<<binarySearch(arr,x,0,n-1)<<endl;
}