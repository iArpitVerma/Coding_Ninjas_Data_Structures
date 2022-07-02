#include<iostream>
using namespace std;
#include"treeNode.h"
treeNode<int>* takeInput(){
    int data;
    cout<<"Enter root data"<<endl;
    cin>>data;
    treeNode<int>* root = new treeNode<int>(data);
    cout<<"Enter number of children"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        treeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printNode(treeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printNode(root->children[i]);
    }
}
int main(){
    treeNode<int>* root = takeInput();
    printNode(root);
}