#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
void printElements(binaryTreeNode<int>* root,int k1, int k2){
    if(root == NULL){
        return;
    }
    if(root->data > k1 && root->data < k2){
        printElements(root->left,k1,k2);
        cout<<root->data<<" ";
        printElements(root->right,k1,k2);
    }
    else if(root->data < k1){
        printElements(root->right,k1,k2);
    }
    else if(root->data > k2){
        printElements(root->left,k1,k2);
    }
    else if(root->data == k1){
        cout<<root->data<<" ";
        printElements(root->right,k1,k2);
    }
    else if(root->data == k2){
        printElements(root->left,k1,k2);
        cout<<root->data<<" ";
    }
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    int k1,k2;
    cin>>k1>>k2;
    printElements(root,k1,k2);
}