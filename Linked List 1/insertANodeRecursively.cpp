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
node* insertNode(node* head, int i, int data){
    if(head == NULL){
        return head;
    }
    if(i==0){
        node* newNode = new node(data);
        newNode->next =head;
        head = newNode;
        return head;
    }

    head->next =  insertNode(head->next,i-1,data);
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
    int i,data;
    cin>>i>>data;
    head = insertNode(head,i,data);
    print(head);
}