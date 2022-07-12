#include <iostream>
#include<climits>
#include"binaryTreeNode.h"
using namespace std;
pair<int,int> minMax(binaryTreeNode<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first = INT_MIN;
        p.second = INT_MAX;
        return p;
    }

    pair<int,int> leftAns = minMax(root->left);
    pair<int,int> rightAns = minMax(root->right);
    int lMax = leftAns.first;
    int lMin = leftAns.second;
    int rMax = rightAns.first;
    int rMin = rightAns.second;

    pair<int,int> p;
    p.first = max(root->data, max(lMax,rMax));
    p.second = min(root->data,min(lMin,rMin));
    return p; 
}

int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    pair<int,int> p = minMax(root);
    cout<<p.second<<" "<<p.first<<endl;
}