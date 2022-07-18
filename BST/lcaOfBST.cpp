#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
binaryTreeNode<int>* LCA(binaryTreeNode<int>* root, int n1,int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }
    else if(root->data > n1 && root->data > n2){
        return LCA(root->left,n1,n2);
    }
    else if(root->data < n1 && root->data < n2){
        return LCA(root->right,n1,n2);
    }else{
        binaryTreeNode<int>* leftAns = LCA(root->left,n1,n2);
        binaryTreeNode<int>* rightAns = LCA(root->right,n1,n2);
        if(leftAns == NULL && rightAns == NULL){
            return NULL;
        }else if(leftAns == NULL){
            return rightAns;
        }else if(rightAns == NULL){
            return leftAns;
        }else{
            return root;
        }
    }
}
int main(){
    binaryTreeNode<int> * root = takeInputLevelWise();
    int n1, n2;
    cin>>n1>>n2;
    if(!LCA(root,n1,n2)){
        cout<<"-1"<<endl;
    }else{
        cout<<LCA(root,n1,n2)->data<<endl;
    }
    delete root;
}