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

// Time Complexity - O(n2)
node* reverse(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* smallAns = reverse(head->next);
    node* temp = smallAns;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}

class pair1{
    public:
    node* head;
    node* tail;
};
// Time Complexity - O(n)
pair1 reverse1(node* head){
    if(head == NULL || head->next == NULL){
        pair1 ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    pair1 smallAns = reverse1(head->next);
    smallAns.tail->next = head;
    smallAns.tail = head;
    head->next = NULL;

    return smallAns;
}

// Time Complexity - O(n)
node* reverse2(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* smallAns = reverse2(head->next);
    node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    
    return smallAns;
}
void print(node* head){
    while(head != NULL ){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    node* head = takeInput();
    // head = reverse(head);
    // head = reverse1(head).head;
    head = reverse2(head);
    print(head);
}