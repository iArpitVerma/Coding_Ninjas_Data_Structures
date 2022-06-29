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
node* deleteNNodes(node* head, int m , int n){
    int c1 = 1, c2 =1;
    node* t1 = head;
    node* t2 = head;
    while(t1 != NULL && t2 != NULL){
        while(c1<m && t1 != NULL){
            t1 = t1->next;
            c1++;
        }
        t2 = t1->next;
        while(c2<n && t2 != NULL){
            node* temp = t2;
            t2 = t2->next;
            c2++;
            delete temp; 
        }
        if(t2 == NULL){
            t1->next = NULL;
            break;
        }
        t2 = t2->next;
        t1->next = t2;
        t1 = t2;
        c1 = 1, c2 = 1;
    }
    return head;
}
void print(node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        node* head = takeInput();
        cin>>m>>n;
        head = deleteNNodes(head,m,n);
        print(head);
    }
}