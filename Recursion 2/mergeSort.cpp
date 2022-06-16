#include <iostream>
using namespace std;
void mergeTwoSortedArrays(int arr[], int si,int ei){
    int mid = (si+ei)/2;
    int i =si , j=mid+1 , index =0 ,l =0;
    int output[ei-si+1];
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            output[index] = arr[i];
            i++, index++ ; 
        }
        else{
            output[index] = arr[j];
            j++, index++ ;
        }
    }
    while(i<=mid){
        output[index] = arr[i];
        index++ ,  i++;
    }

    while(j<=ei){
        output[index] == arr[j];
        j++, index++;
    }
    
    for(int k=si;k<=ei;k++){
        arr[k] = output[l];
        l++;
    }
}
void mergeSort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid = (si + ei)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    mergeTwoSortedArrays(arr,si,ei);
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