#include <iostream>
#include<cmath>
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

// Swap Nodes without swapping their data
node* swap(node* head, int i, int j){
    if(head == NULL){
        return NULL;
    }
    node* p1 = NULL, *c1 = NULL, *n1 = NULL, *p2 = NULL, *c2 = NULL, *n2=NULL;
    for(int k=0;k<min(i,j);k++){
        if(p1 == NULL){
            p1 = head;
        }else{
            p1 = p1->next;
        }
    }
    for(int k=0;k<max(i,j);k++){
        if(p2 == NULL){
            p2 = head;
        }else{
            p2=p2->next;
        }
    }
    if(p1 == NULL){
        c1 = head;
    }else{
        c1 = p1->next;
    }
    n1 = c1->next;
    c2 = p2->next;
    n2 = c2->next; 

    if((i==0 && j== 1) && (i==1 && j==0) ){
        head = c2;
        c1->next = c2->next;
        c2->next = c1;
    }
    else if(i == 0 || j == 0){
        p2->next = c1;
        c1->next = n2;
        c2->next = n1;
        head = c2;
    }
    else if(abs(i-j) == 1){
        p1->next = c2;
        c1->next = c2->next;
        c2->next = c1;
    }
    else{
        p1->next = c2;
        c1->next = n2;
        c2->next = n1;
        p2->next = c1;
    }
    return head;
}
void print(node* head){
    while(head!=NULL){
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
        int i, j;
        cin>>i>>j;
        head = swap(head,i,j);
        print(head);
    }
}