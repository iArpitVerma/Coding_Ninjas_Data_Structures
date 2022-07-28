#include <iostream>
#include<queue>
using namespace std;
// Time Complexity - O(nLogk) = O(n)
int kthLargestElement(int arr[],int n,int k){
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
    return pq.top();
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
    cout<<kthLargestElement(input,n,k)<<endl;
}