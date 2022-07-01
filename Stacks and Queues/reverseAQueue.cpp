#include <iostream>
using namespace std;
#include<queue>
void reverseQueue(queue<int> &q){
    if(q.size() == 0){
        return;
    }

    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        queue<int> q;
        int n;
        cin>>n;
        while(n--){
            int element;
            cin>>element;
            q.push(element);
        }
        reverseQueue(q);
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
}