#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
 int xDepth = 0, xParVal = 0, yDepth = 0, yParVal = 0;
    void helper(binaryTreeNode<int>* root, int x,int y,int dep,int parVal){
        if(root == NULL)return;
        
        if(root->data == x){
            xDepth = dep;
            xParVal = parVal;
        }
        
        if(root->data == y){
            yDepth = dep;
            yParVal = parVal;
        }
        
        helper(root->left,x,y,dep+1,root->data);
        helper(root->right,x,y,dep+1,root->data);
    }
    int isCousins() {
        binaryTreeNode<int>* root = takeInputLevelWise();
        int p,q;
        cin>>p>>q;
        if(root == NULL){
            cout<<"false"<<endl;
            return;
        }
        helper(root,p,q,0,0);
        if(xDepth == yDepth && xParVal != yParVal){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }