#include <iostream>
#include<queue>
using namespace std;
int timeTakenForKthPerson(int arr[],int n ,int k){
    priority_queue<int> pq;
    queue<int> q;
    int time = 0;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        q.push(i);
    }
    while(true){
        if(pq.top() > arr[q.front()]){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        else{
            time++;
            int temp = q.front();
            q.pop();
            pq.pop();
            if(temp == k){
                break;
            }
        }
    }
    return time;
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }    
    int k;
    cin>>k;
    cout<<timeTakenForKthPerson(arr,n,k);
}