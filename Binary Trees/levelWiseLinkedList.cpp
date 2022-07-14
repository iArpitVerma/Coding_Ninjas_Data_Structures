#include <iostream>
#include"binaryTreeNode.h"
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
vector<node*> levelWiseLL(binaryTreeNode<int> * root){
    vector<node*> v;
    if(root == NULL) return v;

    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    node* head = NULL;
    node* tail = NULL;
    while(!pendingNodes.empty()){
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        if(front == NULL){
            v.push_back(head);
            head = NULL;
            tail = NULL;
            if(pendingNodes.empty()){
                break;
            }
            pendingNodes.push(NULL);
            continue;
        }
        node* newNode = new node(front->data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
        }
        if(front->left) pendingNodes.push(front->left);
        if(front->right) pendingNodes.push(front->right);
    }
    return v;
}

int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    vector<node*> v = levelWiseLL(root);
    for(int i=0;i<v.size();i++){
        node* head = v[i];
        while(head!=NULL){
            cout<<head->data<<" ";
            head= head->next;
        }
        cout<<endl;
    }
}