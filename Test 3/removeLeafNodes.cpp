#include <iostream>
#include"treeNode.h"
using namespace std;
treeNode<int>* removeLeafNodes(treeNode<int>* root){
    if(root == NULL) return NULL;
    if(root->children.size() == 0){
        delete root;
        return NULL;
    }

    for(int i=0;i<root->children.size();i++){
        treeNode<int>* child = root->children[i];
        if(child->children.size()== 0){
            delete child;
            for(int j=i;j<root->children.size()-1;j++){
                root->children[j] = root->children[j+1];
            }
            root->children.pop_back();
            i--;
        }
    }

    for(int i=0;i<root->children.size();i++){
        root->children[i] = removeLeafNodes(root->children[i]);
    }
    return root;
}
int main(){
    treeNode<int>* root = takeInputLevelWise();
    removeLeafNodes(root);
    printNodeLevelWise(root);
}

