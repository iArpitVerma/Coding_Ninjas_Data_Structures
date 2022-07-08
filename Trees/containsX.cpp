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

bool checkX(treeNode<int>* root, int x){
    if(root == NULL){
        return false;
    }
    bool ans = false;
    if(root->children.size() == 0){
        if(root->data == x){
            ans = true;
        }
    }
    for(int i=0;i<root->children.size();i++){
        ans = checkX(root->children[i],x);
        if(ans == true){
            return true;
        }
    }
    return ans;
}
int main(){
    treeNode<int>* root = takeInputLevelWise();
    int x;
    cin>>x;
    if(checkX(root,x)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    delete root;
}