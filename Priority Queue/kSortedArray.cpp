#include <iostream>
#include<queue>
using namespace std;
void kSortedArray(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }    
    int j =0;
    for(int i=k;i<n;i++){
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    while(!pq.empty()){
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    kSortedArray(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}