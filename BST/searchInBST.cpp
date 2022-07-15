#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
bool search(binaryTreeNode<int>* root, int k){
    if(root == NULL){
        return false;
    }

    if(root->data == k){
        return true;
    }
    else if(root->data > k){
        return search(root->left,k);
    }else{
        return search(root->right,k);
    }
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    int k;
    cin>>k;
    if(search(root,k)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }


}