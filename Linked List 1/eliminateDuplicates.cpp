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
void eliminateDuplicates(node* head){
    node* t1 = head;
    node* t2 = head->next;
    while(t2 != NULL){
        if(t1->data == t2->data){
            node* p = t2;
            t2 = t2->next;
            t1->next = t2;
            delete p;
        }
        else{
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    t1->next = t2;
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
        eliminateDuplicates(head);
        print(head);
    }
}