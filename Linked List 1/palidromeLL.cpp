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
bool checkPalidrome(node* head){
    int count = 0;
    node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++; 
    }
    int mid = (count - 1)/2;
    node* t1 = head;
    count = 0;
    while(count<mid){
        t1 = t1->next;
        count++;
    }
    node* t2 = t1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        node* head = takeInput();
        if(checkPalidrome(head)){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    
}