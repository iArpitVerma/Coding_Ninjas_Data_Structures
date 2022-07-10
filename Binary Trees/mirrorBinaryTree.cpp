#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
void mirror(binaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }

    binaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    mirror(root);
    printLevelWise(root);
}