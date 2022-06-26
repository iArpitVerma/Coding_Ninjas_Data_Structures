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

node* appendN(node* head, int n){
    if(n==0){
        return head;
    }
    int count = 0;
    int a =0;
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    if(n>=count){
        return head;
    }
    temp->next = head;
    temp = head;
    while(a<count - n){
        temp = temp->next;
        a++;
    }
    head = temp->next;
    temp->next = NULL;
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
        int n;
        cin>>n;
        head = appendN(head,n);
        print(head);
    }
}