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

int height(treeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    if(root->children.size() == 0){
        return 1;
    }
    int temp =0 , Height = 0;
    for(int i=0;i<root->children.size();i++){
        temp = height(root->children[i]);
        if(temp>Height){
            Height = temp;
        }
    }
    return 1 + Height;
}
int main(){
    treeNode<int>* root = takeInputLevelWise();
    cout<<height(root)<<endl;
    delete root;
}