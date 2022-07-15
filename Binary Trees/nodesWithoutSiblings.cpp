#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
void nodesWithoutSiblings(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    if(root->left && !root->right){
        cout<<root->left->data<<" ";
        nodesWithoutSiblings(root->left);
    }else if(root->right && !root->left){
        cout<<root->right->data<<" ";
        nodesWithoutSiblings(root->right);
    }else{
        nodesWithoutSiblings(root->left);
        nodesWithoutSiblings(root->right);
    }
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    nodesWithoutSiblings(root);
}