#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
int replace(binaryTreeNode<int>* root, int sum){
    if(root == NULL) return sum;

    sum = replace(root->right,sum);
    sum = sum + root->data;
    root->data = sum;
    sum = replace(root->left,sum);
    return sum;
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    replace(root,0);
    printLevelWise(root);
}