#include <iostream>
#include"binaryTreeNode.h"
using namespace std;

void print(binaryTreeNode<int>* root, int k, string s){
    if(root == NULL || k<0){
        return;
    }
    if(k == root->data && root->left == NULL && root->right == NULL){
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }
        cout<<root->data<<endl;
    }

    print(root->left, k - root->data, s + to_string(root->data));
    print(root->right,k - root->data, s + to_string(root->data));
    
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    int k;
    cin>>k;
    print(root,k,"");
}