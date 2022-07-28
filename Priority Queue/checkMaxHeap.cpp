#include <iostream>
using namespace std;
bool checkMaxHeap(int arr[], int n){
    for(int i=0;i<n;i++){
        int parentIndex = i;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        if(leftChildIndex < n){
            if(arr[leftChildIndex] > arr[parentIndex] ){
                return false;
            }
        }else{
            break;
        }
        if(rightChildIndex < n){
            if((arr[rightChildIndex] > arr[parentIndex])){
                return false;
            }
        }else{
            break;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(checkMaxHeap(arr,n)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}