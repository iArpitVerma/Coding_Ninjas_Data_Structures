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
bool identical(treeNode<int>* root1, treeNode<int>* root2){
    bool ans = true;
    if(root1->data != root2->data){
        return false;
    }
    if(root1->children.size() != 0 && root2->children.size() == 0){
        return false;
    }
    for(int i=0;i<root1->children.size();i++){
        ans = identical(root1->children[i],root2->children[i]);
        if(ans == false){
            return false;
        }
    }
    return ans;
}
int main(){
    treeNode<int>* root1 = takeInputLevelWise();
    treeNode<int>* root2 = takeInputLevelWise();
    if(identical(root1,root2)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    delete root1,root2;
}