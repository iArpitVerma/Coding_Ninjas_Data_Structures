#include <iostream>
#include<queue>
using namespace std;
int* kLargestElements(int arr[],int n, int k){
    // Min Heap i.e Min PQ
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int* output = new int[k];
    int i =0;
    while(!pq.empty()){
        output[i] = pq.top();
        pq.pop();
        i++;
    }
    return output;
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int k;
    cin>>k;
    int *arr = kLargestElements(input,n,k);
    for(int i=0;i<k;i++){
        cout<<arr[i]<<endl;
    }
}