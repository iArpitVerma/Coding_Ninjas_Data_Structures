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
int findNode(node* head , int n){
    int i=0;
    while(head != NULL){
        if(head->data == n){
            return i;
        }
        head = head->next; 
        i++;
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        node* head = takeInput();
        int n;
        cin>>n;
        cout<<findNode(head,n)<<endl;
    }
}