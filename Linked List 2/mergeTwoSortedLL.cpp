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
node* mergeTwoLL(node* h1, node* h2){
    node* fH = NULL;
    node* fT = NULL;
    if(h1 != NULL && h2 != NULL){
        if(h1->data <= h2->data){
            fH = h1;
            fT = h1;
            h1 = h1->next;
        }
        else{
            fH = h2;
            fT = h2;
            h2 = h2->next;
        }
    }
    while(h1 != NULL && h2 != NULL){
        if(h1->data <= h2->data){
            fT->next = h1;
            fT = h1;
            h1 = h1->next;
        }else{
            fT->next = h2;
            fT = h2;
            h2 = h2->next;
        }
    }
    if(h1 == NULL){
        fT->next = h2;
    }else if(h2 == NULL){
        fT->next = h1;
    }

    return fH;
}
void print(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        node* h1 = takeInput();
        node* h2 = takeInput();
        node* h3 = mergeTwoLL(h1,h2);
        print(h3);
    }
}