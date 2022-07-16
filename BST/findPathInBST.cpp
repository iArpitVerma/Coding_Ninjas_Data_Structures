#include <iostream>
#include"binaryTreeNode.h"
using namespace std;

vector<int>* findPath(binaryTreeNode<int>* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftAns = findPath(root->left, data);
    if(leftAns != NULL){
        leftAns->push_back(root->data);
        return leftAns;
    }

    vector<int>* rightAns = findPath(root->right, data);
    if(rightAns!=NULL){
        rightAns->push_back(root->data);
        return rightAns;
    }else{
        return NULL;
    }
}

int main(){
    binaryTreeNode<int>* root = takeInputLevelWise();
    int data;
    cin>>data;
    vector<int>* output = findPath(root,data);
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<endl;
    }
    delete output;
}