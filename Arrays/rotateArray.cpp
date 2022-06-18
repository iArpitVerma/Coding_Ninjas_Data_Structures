#include <iostream>
using namespace std;
void reverseArray(int * arr, int si,int ei){
    while(si<ei){
        int temp = arr[si];
        arr[si] = arr[ei];
        arr[ei] = temp;
        si++,ei--;
    }
}
void rotateArray(int * arr, int n,int d){
    reverseArray(arr,0,n-1);
    reverseArray(arr,0,n-d-1);
    reverseArray(arr,n-d,n-1);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n;
        int * arr= new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>d;
        rotateArray(arr,n,d);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        delete []arr;
    }
}  