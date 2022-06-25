#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node* takeInput(){
    int count = 0;
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next =newNode;
            tail = tail->next;
        }
        count++;
        cin>>data;
    }
    return head; 
}

int length(Node* const head){
    Node* temp = head;
    int count =0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Node* head = takeInput();
        cout<<length(head)<<endl;
    }
}