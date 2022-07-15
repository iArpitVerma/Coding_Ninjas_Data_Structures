#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
binaryTreeNode<int>* construct(int arr[], int si,int ei){
    if(si>ei){
        return NULL;
    }    

    int mid = (si+ei)/2;
    binaryTreeNode<int>* root = new binaryTreeNode<int>(arr[mid]);
    root->left = construct(arr,si,mid-1);
    root->right = construct(arr,mid+1,ei);
    return root;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    binaryTreeNode<int>* root = construct(arr,0,n-1);
    printLevelWise(root);
}