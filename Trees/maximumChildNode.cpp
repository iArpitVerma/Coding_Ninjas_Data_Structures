#include <iostream>
#include<queue>
#include"treeNode.h"
using namespace std;
class pair1{
    public:
    treeNode<int> * node;
    int data;

    pair1(){
        data = 0;
        node = NULL;
    }

};
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

pair1 result(treeNode<int>* root, pair1 a){
    int sum = root->data;
    for(int i=0;i<root->children.size();i++){
        sum = sum + root->children[i]->data;
    }
    if(sum>a.data){
        a.data = sum;
        a.node = root;
    }
    for(int i=0;i<root->children.size();i++){
        a = result(root->children[i],a);
    }
    return a;
}
treeNode<int>* maximumChildNode(treeNode<int>* root){
   pair1 a;
   a = result(root,a);
   return a.node;
}
int main(){
    treeNode<int>* root = takeInputLevelWise();
    cout<<maximumChildNode(root)->data<<endl;
    delete root;
}