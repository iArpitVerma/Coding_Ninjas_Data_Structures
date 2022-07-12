#include <iostream>
#include"binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* removeLeafNodes(binaryTreeNode<int>* root){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    } 

    if(root->left){
        root->left = removeLeafNodes(root->left);
    }
    if(root->right){
        root->right = removeLeafNodes(root->right);
    }
    return root;
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    root = removeLeafNodes(root);
    printLevelAtNewLine(root);
}