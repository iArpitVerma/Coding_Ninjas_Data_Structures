#include <iostream>
#include<stack>
#include"binaryTreeNode.h"
using namespace std;
void zigzagTree(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    stack<binaryTreeNode<int>*> s1;
    stack<binaryTreeNode<int>*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        if(s2.empty()){
            while(!s1.empty()){
                binaryTreeNode<int>* top = s1.top();
                s1.pop();
                cout<<top->data<<" ";
                if(top->left) s2.push(top->left);
                if(top->right) s2.push(top->right);
            }
        }else{
            while(!s2.empty()){
                binaryTreeNode<int>* top = s2.top();
                s2.pop();
                cout<<top->data<<" ";
                if(top->right)s1.push(top->right);
                if(top->left)s1.push(top->left);
            }
        }
        cout<<endl;
    }
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    zigzagTree(root);    
}