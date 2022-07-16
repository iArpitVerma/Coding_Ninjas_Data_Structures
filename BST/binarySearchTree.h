#include<bits/stdc++.h>
#include"binaryTreeNode.h"
class BST{
    binaryTreeNode<int>* root;

    public:
    BST(){
        root = NULL;
    }

    ~BST(){
        delete root;
    }

    private:
    bool hasData(binaryTreeNode<int>* node, int data){
        if(node == NULL){   
            return false;
        }

        if(node->data == data){
            return true;
        }else if(data < node->data){
            hasData(node->left,data);
        }else{
            hasData(node->right,data);
        }
    }

    binaryTreeNode<int>* insertData(binaryTreeNode<int>* node, int data){
        if(node == NULL){
            node = new binaryTreeNode<int>(data);
            return node;
        }
        else if( data < node->data){
            node->left = insertData(node->left,data);
        }
        else{
            node->right = insertData(node->right,data);
        }
    }
    binaryTreeNode<int>* rightMin(binaryTreeNode<int>* node){
        binaryTreeNode<int>* min = new binaryTreeNode<int>(INT_MAX);
        if(node->left) rightMin(node->left);
        if(node->data < min->data){
            min = node;
        }
        return min;
        
    }
    binaryTreeNode<int>* deleteData(binaryTreeNode<int>* node, int data){
        if(node == NULL){
            return NULL;
        }
        if(data == node->data){
            if(node->left == NULL && node->right == NULL){
                return NULL;
            }else if(node->left == NULL && node->right != NULL){
                return node->right;
            }else if(node->left != NULL && node->right == NULL){
                return node->left;
            }else{
                node->data = rightMin(node->right)->data;
                deleteData(node->right,node->data);
            }
        }
        else if(data < root->data){
            deleteData(node->left,data);
        }else{
            deleteData(node->right,data);
        }
    }

    public:
    bool hasData(int data){
        return hasData(root,data);
    }

    void insertData(int data){
        insertData(root,data);
    }

    void deleteData(int data){
        deleteData(root,data);
    }


};