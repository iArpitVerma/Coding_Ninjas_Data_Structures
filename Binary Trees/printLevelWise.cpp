#include <iostream>
#include<queue>
#include"binaryTreeNode.h"
using namespace std;
void printLevelWise1(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<" : ";
        if(front->left){
            cout<<"L"<<front->left->data<<" ";
            pendingNodes.push(front->left);
        }
        
        if(front->right){
            cout<<"R"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise1(root);
    delete root;
}