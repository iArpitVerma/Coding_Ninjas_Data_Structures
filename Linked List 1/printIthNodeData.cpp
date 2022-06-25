#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head ==NULL){
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
int nodeData(Node* const head, int i){
    Node* temp = head;
    for(int j=0;j<i;j++){
        temp = temp->next;
    }
    return temp->data;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Node* head = takeInput();
        int i;
        cin>>i;
        cout<<nodeData(head,i)<<endl;
    }
}