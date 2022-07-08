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

int countNodes(treeNode<int>* root,int x){
    int count = 0;
    if(root == NULL){
        return 0;
    }
    if(root->data > x){
        count++;
    }
    for(int i=0;i<root->children.size();i++){
        count = countNodes(root->children[i],x) + count;    
    }
    return count;
}

int main(){
    treeNode<int>* root = takeInputLevelWise();
    int x;
    cin>>x;
    cout<<countNodes(root,x)<<endl;
    delete root;
}