#include <iostream>
#include"binaryTreeNode.h"
using namespace std;
int height(binaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

// Time Complexity = O(n*height) = O(n2) or O(nlogn); 
int diameter(binaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2,option3));
}

// Time Complexity = O(n)
pair<int,int> diameterHeight(binaryTreeNode<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftAns = diameterHeight(root->left);
    pair<int,int> rightAns = diameterHeight(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    pair<int,int> p;
    p.first = 1 + max(lh,rh);
    p.second = max(lh+rh, max(ld,rd));
    return p;
}

int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    cout<<"Height : "<<diameterHeight(root).first<<endl;
    cout<<"Diameter : "<<diameterHeight(root).second<<endl;
}