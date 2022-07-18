#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
void createInsertDuplicateNode(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    binaryTreeNode<int>* duplicate = new binaryTreeNode<int>(root->data);
    if(root->left){
        binaryTreeNode<int>* temp = root->left;
        root->left = duplicate;
        duplicate->left = temp;
    }else{
        root->left = duplicate;
    } 

    createInsertDuplicateNode(root->left->left);
    createInsertDuplicateNode(root->right);   
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    createInsertDuplicateNode(root);
    printLevelWise(root);
    delete root;
}