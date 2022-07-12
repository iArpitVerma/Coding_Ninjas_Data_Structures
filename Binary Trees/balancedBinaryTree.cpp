#include <iostream>
#include"binaryTreeNode.h"
using namespace std;

pair<bool,int> checkBalanced(binaryTreeNode<int>* root){
    if(root == NULL){
        pair<bool,int> p;
        p.first = true;
        p.second = 0;
        return p;
    }

    pair<bool,int> leftAns = checkBalanced(root->left);
    pair<bool,int> rightAns = checkBalanced(root->right);
    bool lB = leftAns.first;
    int  lH = leftAns.second;
    bool rB = rightAns.first;
    int rH = rightAns.second;

    pair<bool,int> p;
    if((lB == true && rB == false) || (lB == false && rB == true) || (lB == false && rB == false) ){
        p.first = false;
    }else{
        if( abs(lH-rH) <= 1  ){
            p.first = true;
        }else{
            p.first = false;
        }
    }   
    p.second = 1 + max(lH,rH);
    return p; 
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    if(checkBalanced(root).first){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}