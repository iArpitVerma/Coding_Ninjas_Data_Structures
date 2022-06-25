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
node* deleteNode(node* head,int pos){
    node* temp = head;
    int i=0;
    if(pos == 0){
        node* a = head;
        head = head->next;
        delete a;
        return head;
    }
    while(i<pos-1 && temp != NULL){
        temp = temp->next;
        i++;
    }
    if(temp != NULL){
        node* a = temp->next;
        node* b = a->next;
        temp->next = b;
        delete a;
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
    int t;
    cin>>t;
    while(t--){
        node* head = takeInput();
        int pos;
        cin>>pos;
        head = deleteNode(head,pos);
        print(head);
    }
}