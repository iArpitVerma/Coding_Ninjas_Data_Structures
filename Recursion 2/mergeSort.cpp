#include <iostream>
using namespace std;
void merge(int arr[],int si, int mid, int ei){
    int temp[ei-si+1];
    int i = si, j = mid+1, k=0;
    while(i<=mid && j<=ei){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }
    
    while(j<=ei){
        temp[k++] = arr[j++];
    }

    for(int t=0;t<k;t++){
        arr[si++] = temp[t];
    }
}
void mergeSort(int arr[], int si,int ei){
    if(si >= ei){
        return;
    }

    int mid = (si+ei)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);

    merge(arr,si,mid,ei);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}