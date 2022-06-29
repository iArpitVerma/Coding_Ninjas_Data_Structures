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
node* evenAfterOdd(node* head){
    node* oH = NULL; // Odd Head
    node* oT = NULL; // Odd Tail
    node* eH = NULL; // Even Head
    node* eT = NULL; // Even Tail
    if(head == NULL){
        return head;
    }
    while(head != NULL ){
        if(head->data % 2 == 0){
            if(eH == NULL){
                eH = head;
                eT = head;
            }else{
                eT->next = head;
                eT = head;
            }
        }else{
            if(oH == NULL){
                oH = head;
                oT = head;
            }else{
                oT->next = head;
                oT = head;
            }
        }
        head = head->next;
    }
    eT->next = NULL;
    oT->next = eH;
    return oH;
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
        node* head = takeInput();
        head = evenAfterOdd(head);
        print(head);
    }
}