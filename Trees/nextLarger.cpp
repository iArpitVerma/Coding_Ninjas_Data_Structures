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
treeNode<int>* nextLarger(treeNode<int>* root, int x){
    if(root == NULL){
        return NULL;
    }
    treeNode<int>* ans = NULL;
    if(root->data > x){
        ans = root;
    }
    for(int i=0;i<root->children.size();i++){
        treeNode<int>* temp = nextLarger(root->children[i],x);
        if(ans == NULL){
            ans = temp;
        }
        else if(temp!=NULL && temp->data < ans->data){
            ans = temp;
        }
    }
    return ans;
}
int main(){
    int x;
    cin>>x;
    treeNode<int>* root = takeInputLevelWise();
    cout<<nextLarger(root,x)->data<<endl;
    delete root;
}