#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
int height(binaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int lh = 1 + height(root->left);
    int rh = 1 + height(root->right);
    if(lh>rh){
        return lh;
    }else{
        return rh;
    } 
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    cout<<height(root)<<endl;
    delete root;
}