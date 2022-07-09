#include <bits/stdc++.h>
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
void replaceWithDepth(treeNode<int>* root, int depth = 0){
    if(root == NULL){
        return;
    }
    root->data = depth;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepth(root->children[i],depth+1);
    }
}

void printNodeLevelWise(treeNode<int>* root){
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<" : ";
        for(int i=0;i<front->children.size();i++){
            treeNode<int>* child = front->children[i];
            pendingNodes.push(child);
            if(i == front->children.size() - 1){
                cout<<child->data;
            }else{
                cout<<child->data<<",";
            }
        }
        cout<<endl;    
    }

}

int main(){
    treeNode<int>* root = takeInputLevelWise();
    replaceWithDepth(root);
    printNodeLevelWise(root);    
}