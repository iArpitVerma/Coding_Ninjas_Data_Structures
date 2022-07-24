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
    while(data!=-1){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}
void deleteAlternateNodes(node* head){
    if(head == NULL || head->next == NULL){
        return;
    }
    node* temp= head;
    while(temp->next){
        node* a = temp->next;
        temp->next = a->next;
        temp = a->next;
        delete a;
    }
}
void print(node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    node* head = takeInput();
    deleteAlternateNodes(head);
    print(head);
}