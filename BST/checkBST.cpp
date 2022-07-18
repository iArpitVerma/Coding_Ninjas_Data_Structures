#include<bits/stdc++.h>
#include"binaryTreeNode.h"
using namespace std;

// 1st Approach
int minimum(binaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left),minimum(root->right)));
}
int maximum(binaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }

    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
// Time Complexity - O(n*height) - O(n2) or O(nlogn)
bool isBST1(binaryTreeNode<int>* root){
    if(root == NULL) return true;

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data >leftMax) && (root->data <= rightMin) && isBST1(root->left) && isBST1(root->right);
    return output;
}


// 2nd Approach
class isBSTReturn{
    public:
    int minimum;
    int maximum;
    bool isBST;
};
// Time Complexity - O(n)
isBSTReturn isBST2(binaryTreeNode<int>* root){
    if(root == NULL){
        isBSTReturn output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBST = true;
        return output;
    }

    isBSTReturn leftAns = isBST2(root->left);
    isBSTReturn rightAns = isBST2(root->right);

    int minimum = min(root->data, min(leftAns.minimum,rightAns.minimum));
    int maximum = max(root->data,max(leftAns.maximum,rightAns.maximum));
    bool BST = (leftAns.isBST && rightAns.isBST) && (root->data > leftAns.maximum) && (root->data <= rightAns.minimum);

    isBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = BST;
    return output;
}


// 3rd Approach
// Time Complexity - O(n) 
bool isBST3(binaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }

    if(root->data < min || root->data > max){
        return false;
    }

    bool leftAns, rightAns;
    if(root->data == min){
        if(root->left == NULL){
            leftAns = true;
        }else{
            leftAns = false;
        }
    }else{
        leftAns = isBST3(root->left,min,root->data-1);
    }

    if(root->data == max){
        if(root->right == NULL){
            rightAns = true;
        }else{
            rightAns = false;
        }
    }else{
        rightAns = isBST3(root->right,root->data,max);
    }
    return leftAns && rightAns ;
}

int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    if(isBST2(root).isBST){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    delete root;
}