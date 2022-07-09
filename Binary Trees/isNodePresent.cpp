#include <iostream>
#include"binaryTreeNode.h"
using namespace std;

bool checkNodePresent(binaryTreeNode<int>* root ,int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }

    if(checkNodePresent(root->left,data)){
        return true;
    }
    if(checkNodePresent(root->right,data)){
        return true;
    }
    return false;;
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    int data;
    cin>>data;
    if(checkNodePresent(root,data)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}