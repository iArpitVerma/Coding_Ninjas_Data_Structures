#include <iostream>
#include<queue>
#include"treeNode.h"
using namespace std;
treeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;

    treeNode<int>* root = new treeNode<int>(rootData);
    queue<treeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cout<<"Enter num of children of "<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int data;
            cout<<"Enter "<<i<<"th child data"<<endl;
            cin>>data;
            treeNode<int>* child = new treeNode<int>(data);
            pendingNodes.push(child);
            front->children.push_back(child);
        } 
    }
    return root;
}

void preOrderTraversal(treeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preOrderTraversal(root->children[i]);
    }
}
void postOrderTraversal(treeNode<int>* root){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postOrderTraversal(root->children[i]);
    }
    cout<<root->data<<" ";
}
int main(){
    treeNode<int>* root = takeInputLevelWise();
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    delete root;
}