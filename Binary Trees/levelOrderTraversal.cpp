#include <iostream>
#include"binaryTreeNode.h"
using namespace std;

void printLevelOrder(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    while(!pendingNodes.empty()){
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        if(front == NULL){
            cout<<endl;
            if(pendingNodes.empty()){
                break;
            }
            pendingNodes.push(NULL);
            continue;
        }
        cout<<front->data<<" ";    

        if(front->left){
            pendingNodes.push(front->left);
        }
        if(front->right){
            pendingNodes.push(front->right);
        }
    }
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    printLevelOrder(root);
}