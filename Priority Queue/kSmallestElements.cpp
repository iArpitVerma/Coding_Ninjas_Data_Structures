#include <iostream>
#include<queue>
using namespace std;
int* kSmallestElements(int input[],int n, int k){
    // Max Heap i.e Max PQ
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    for(int i=k;i<n;i++){
        if(input[i] < pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }

    int* arr = new int[k];
    for(int i=0;i<k;i++){
        arr[i] = pq.top();
        pq.pop();
    }
    return arr;
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
    int *arr = kSmallestElements(input,n,k);
    for(int i=0;i<k;i++){
        cout<<arr[i]<<endl;
    }
}