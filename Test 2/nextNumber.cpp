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
void print(node* head){
    if(head == NULL) return;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node* reverseLL(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* smallAns = reverseLL(head->next);
    node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}
node* nextNumber(node* head){
    if(head == NULL) return NULL;
    head = reverseLL(head);
    if(head->data<9){
        head->data+=1;
    }else{
        int carry = 1;
        node* temp = head;
        while(carry == 1){
            if(temp->data == 9){
                temp->data = 0;
                carry = 1;
                if(temp->next == NULL){
                    node* newNode = new node(1);
                    temp->next = newNode;
                    break;
                }
                temp = temp->next;
            }else{
                temp->data += 1;
                carry = 0;
            }
        }
    }
    head = reverseLL(head);
    return head;
}
int main(){
    node* head = takeInput();
    head = nextNumber(head);
    print(head);
}