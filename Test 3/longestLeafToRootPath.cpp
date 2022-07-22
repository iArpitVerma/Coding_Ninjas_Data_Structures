#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
int height(binaryTreeNode<int>* root){
    if(root == NULL) return 0;
    
    int leftAns = height(root->left);
    int rightAns = height(root->right);

    return 1 + max(leftAns,rightAns);
}
vector<int> longestPath(binaryTreeNode<int>* root){
    vector<int> v;
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->data);
        return v;
    }

    int lH = 0, rH = 0;
    if(root->left){
        lH = height(root->left);
    }
    if(root->right){
        rH = height(root->right);
    }

    if(lH>rH){
        v = longestPath(root->left);
        v.push_back(root->data);
    }else{
        v = longestPath(root->right);
        v.push_back(root->data);
    }

    return v;
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    vector<int> v = longestPath(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}