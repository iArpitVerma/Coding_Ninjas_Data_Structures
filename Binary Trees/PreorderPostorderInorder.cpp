#include <iostream>
#include"binaryTreeNode.h"
using namespace std;

// root -> left -> right
void preorder(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// left -> right -> root
void postorder(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// left -> root -> right  
void inorder(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
}