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
node* insertNode(node* head,int pos){
    int data;
    int count = 0;
    cin>>data;
    node* newNode = new node(data);
    if(pos == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    node* temp = head;
    if(count<pos-1 && temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(temp!=NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}
int main(){
    node* head = takeInput();
    int pos;
    cin>>pos;
    head = insertNode(head,pos);
    print(head);
}