#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
void printAtDepthK(binaryTreeNode<int>* root, int k){
    if(root == NULL) return;
    if(k == 0){
        cout<<root->data<<endl;
        return;
    }
    printAtDepthK(root->left,k-1);
    printAtDepthK(root->right,k-1);
}
// Returns distance of root from the target node
// -1 if target node is not present
int print(binaryTreeNode<int>* root, int k, int val){
    if(root == NULL) return -1;
    if(root->data == val){
        printAtDepthK(root,k);
        return 0;
    }

    int leftAns  = print(root->left,k,val);
    if(leftAns != -1 ){
        if(leftAns + 1 == k) cout<<root->data<<endl;
        else if(leftAns + 1 < k){
            printAtDepthK(root->right,k-leftAns - 2);
        }
        return 1 + leftAns;
    }

    int rightAns = print(root->right,k,val);
    if(rightAns != -1){
        if(rightAns + 1 == k) cout<<root->data<<endl;
        else if(rightAns + 1 < k){
            printAtDepthK(root->left,k-rightAns-2);
        }
        return 1 + rightAns;
    }

    return -1;
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    int val,k;
    cin>>val>>k;
    print(root,k,val);
}