#include <bits/stdc++.h>
#include<queue>
#include"treeNode.h"
using namespace std;
class pair1{
    public:
    treeNode<int>* max;
    treeNode<int>* smax;
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
pair1 secondLargest(treeNode<int>* root){
    pair1 ans;
    ans.max = root;
    ans.smax = NULL;
    for(int i=0;i<root->children.size();i++){
        pair1 temp = secondLargest(root->children[i]);
        if(temp.max->data <= ans.max->data){
            if(ans.smax == NULL || (ans.smax->data < temp.max->data)){
                ans.smax = temp.max;
            }
        }
        else{

            if(temp.smax == NULL){
                ans.smax = ans.max;
                ans.max = temp.max;
            }
            else{
                if(ans.max->data < temp.smax->data){
                    ans.smax = temp.smax;
                    ans.max = temp.max;
                }else if(ans.max->data > temp.smax->data){
                    ans.smax = ans.max;
                    ans.max = temp.max;
                }
            }
        }
    }
    return ans;
}
int main(){
    treeNode<int>* root = takeInputLevelWise();
    cout<<secondLargest(root).smax->data<<endl;
    delete root;
}