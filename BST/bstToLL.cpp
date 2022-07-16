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
pair<node*,node*> bstToLL(binaryTreeNode<int>* root){
    if(root == NULL){
        pair<node*,node*> output;
        output.first = NULL;
        output.second = NULL;
        return output;
    }

    pair<node*,node*> leftAns = bstToLL(root->left);
    pair<node*,node*> rightAns = bstToLL(root->right);

    node* lh = leftAns.first;
    node* lt = leftAns.second;
    node* rh = rightAns.first;
    node* rt = rightAns.second;

    node* newNode = new node(root->data);
    pair<node*,node*> output;

    if(lh == NULL && rh == NULL){
        output.first  = newNode;
        output.second = newNode;
    }else if(lh == NULL && rh != NULL){
        output.first = newNode;
        newNode->next = rh;
        output.second = rt;
    }
    else if(lh != NULL && rh == NULL){
        output.first = lh;
        lt->next = newNode;
        output.second = newNode;
    }
    else{
        lt->next = newNode;
        newNode->next = rh;
        output.first = lh;
        output.second = rt;
    }
    return output;
}
int main(){
   binaryTreeNode<int>* root = takeInputLevelWise();
   node* head = bstToLL(root).first;
   while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;  
   }

}