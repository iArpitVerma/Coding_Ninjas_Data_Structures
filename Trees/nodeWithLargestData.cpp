#include<bits/stdc++.h>
#include"treeNode.h"
#include<queue>
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

// Level Wise
treeNode<int>* largestNode(treeNode<int>* root){
    treeNode<int>* max = new treeNode<int>(INT_MIN);
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        if(front->data > max->data){
            max = front;
        }
        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return max;
}

// Recursive
treeNode<int>* largestNode1(treeNode<int>* root){
    treeNode<int>* max = new treeNode<int>(root->data);

    for(int i=0;i<root->children.size();i++){
        treeNode<int>* child = largestNode1(root->children[i]);
        if(child->data > max->data){
            max = child;
        }
    }
    return max;
}
int main(){
    treeNode<int>* root = takeInputLevelWise();
    cout<<largestNode1(root)->data<<endl;
    delete root;
}