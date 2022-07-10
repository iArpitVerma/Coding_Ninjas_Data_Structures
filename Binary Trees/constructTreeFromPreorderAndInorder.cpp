#include <iostream>
#include"binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* constructTree(int* preorder, int* inorder , int preS, int preE, int inS,int inE){
    if(inS>inE){
        return NULL;
    }

    int rootData = preorder[preS];
    int rootIndex = -1;
    for(int i = inS; i<=inE ;i++){
        if(inorder[i] == rootData){
            rootIndex = i;
            break;
        }
    }

    int lInS = inS; 
    int lInE = rootIndex - 1 ;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preS;

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    root->left = constructTree(preorder,inorder,lPreS,lPreE,lInS,lInE);
    root->right = constructTree(preorder,inorder,rPreS,rPreE,rInS,rInE);

    return root;
}
int main(){
    int n;
    cin>>n;
    int* preorder = new int[n];
    int* inorder = new int[n];
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    binaryTreeNode<int>* root  = constructTree(preorder,inorder,0,n-1,0,n-1);
    printLevelAtNewLine(root);
    delete root;
}