#include <iostream>
#include"binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* constructTree(int* pos, int* in, int poS, int poE, int inS, int inE){
    if(inS>inE){
        return NULL;
    }

    int rootData = pos[poE];
    int rootIndex = -1;
    for(int i=inS;i<=inE;i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPoS = poS;
    int lPoE = lInE - lInS + lPoS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPoS = lPoE + 1;
    int rPoE = rInE - rInS + rPoS;

    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    root->left = constructTree(pos,in,lPoS,lPoE,lInS,lInE);
    root->right = constructTree(pos,in,rPoS,rPoE,rInS,rInE);

    return root;
}
int main(){
    int n;
    cin>>n;
    int* pos = new int[n];
    int* in = new int[n];
    for(int i=0;i<n;i++){
        cin>>pos[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    binaryTreeNode<int>* root = constructTree(pos,in,0,n-1,0,n-1);
    printLevelAtNewLine(root);
}