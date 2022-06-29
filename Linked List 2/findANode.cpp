#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};
node* takeInput(){
    int data;
    cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data != -1){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}
int findANode(node* head, int n){
    if(head == NULL){
        return -1;
    }

    if(head->data == n){
        return 0;
    }
    int smallAns = findANode(head->next,n);
    if(smallAns == -1){
        return -1;
    }
    return 1 + smallAns; 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        node* head = takeInput();
        int n;
        cin>>n;
        cout<<findANode(head,n)<<endl;
    }
}