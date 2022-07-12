#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
int sumOfNodes(binaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int leftAns = sumOfNodes(root->left);
    int rightAns = sumOfNodes(root->right);
    return root->data + leftAns + rightAns;
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    cout<<sumOfNodes(root)<<endl;
}