#include <bits/stdc++.h>
#include"binaryTreeNode.h"
using namespace std;

// Time Complexity - O( n + nlogn + n) = O(nlogn)
void preorder(binaryTreeNode<int>* root,vector<int> &v){
    if(root == NULL){
        return;
    }
    v.push_back(root->data);
    preorder(root->left,v);
    preorder(root->right,v);
}

void printPairs(vector<int> v, int sum){
    int i=0, j = v.size() -1;
    while(i<j){
        if(v[i] + v[j] == sum){
            cout<<v[i]<<" "<<v[j]<<endl;
            i++,j--;
        }
        else if(v[i] + v[j] > sum){
            j--;
        }else{
            i++;
        }
    }
}
int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    int sum;
    cin>>sum;
    vector<int> v;
    preorder(root,v);
    sort(v.begin(),v.end());
    printPairs(v,sum);
    delete root;
}