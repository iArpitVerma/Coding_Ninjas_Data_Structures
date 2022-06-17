#include <iostream>
using namespace std;
void swap(int arr[],int si,int c){
    int temp = arr[si];
    arr[si] = arr[c];
    arr[c] = temp;
}
int partition(int arr[],int si, int ei){
    int count = 0;
    for(int i=si+1;i<=ei;i++){
        if(arr[si]>=arr[i]){
            count++;
        }
    }
    swap(arr,si,si+count);
    int i =si , j=ei;
    while(i<si+count && j>si+count){
        if(arr[i]<=arr[si+count]){
            i++;
        }
        else if(arr[j]>arr[si+count]){
            j--;
        }
        else{
            swap(arr,i,j);
            i++,j--;
        }
    }
    return si+count;    
}
void quickSort(int arr[] ,int si,int ei){
    if(si>=ei){
        return;
    }
    int pivotIndex = partition(arr,si,ei);
    quickSort(arr,si,pivotIndex - 1);
    quickSort(arr,pivotIndex + 1,ei); 
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}