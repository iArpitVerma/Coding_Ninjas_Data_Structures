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
node* reverse(node* head){
    node* prev = NULL;
    node* current = head;
    node* nxt = head->next;
    while(current != NULL){
        current->next = prev;
        prev = current;
        current = nxt;
        if(nxt == NULL){break;}
        nxt = nxt->next;
    }
    return prev;
}

void print(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    node* head = takeInput();
    head = reverse(head);
    print(head);
}