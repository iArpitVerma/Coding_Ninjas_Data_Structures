#include <bits/stdc++.h>
#include"binaryTreeNode.h"
using namespace std;
class isBST{
    public:
    int minimum;
    int maximum;
    bool isBst;
    int height;
};

// Time Complexity - O(n)
isBST heightOfBST(binaryTreeNode<int>* root){
    if(root == NULL){
        isBST output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBst = true;
        output.height = 0;
        return output;
    }

    isBST leftAns = heightOfBST(root->left);
    isBST rightAns = heightOfBST(root->right);

    int minData = min(root->data,min(leftAns.minimum,rightAns.minimum));
    int maxData = max(root->data,max(leftAns.maximum,rightAns.maximum));
    bool checkBST = (leftAns.isBst && rightAns.isBst) && (root->data > leftAns.maximum) && (root->data < rightAns.minimum);
    int BstHeight;
    if(checkBST){
        BstHeight = 1 + max(leftAns.height,rightAns.height);
    }else{
        BstHeight = max(leftAns.height,rightAns.height);
    }

    isBST output;
    output.minimum = minData;
    output.maximum = maxData;
    output.isBst = checkBST;
    output.height = BstHeight;
    return output;
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    cout<<heightOfBST(root).height<<endl;
    delete root;        
}