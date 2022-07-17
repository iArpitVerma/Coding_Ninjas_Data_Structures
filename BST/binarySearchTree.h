#include<iostream>
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
    // Time Complexity = O(height)
    bool hasData(binaryTreeNode<int>* node, int data){
        if(node == NULL){   
            return false;
        }

        if(data == node->data){
            return true;
        }else if(data < node->data){
            hasData(node->left,data);
        }else{
            hasData(node->right,data);
        }
    }

    // Time Complexity = O(height)
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
        return node;
    }

    // Time Complexity = O(height)
    binaryTreeNode<int>* deleteData(binaryTreeNode<int>* node, int data){
        if(node == NULL){
            return NULL;
        }
        if(data == node->data){
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }else if(node->left == NULL && node->right != NULL){
                binaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else if(node->left != NULL && node->right == NULL){
                binaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else{
                binaryTreeNode<int>* minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right,rightMin);
                return node;
            }
        }
        else if(data < node->data){
            node->left = deleteData(node->left,data);
            return node;
        }else{
            node->right = deleteData(node->right,data);
            return node;
        }
    }

void printTree (binaryTreeNode<int> *root) {
   if(root == NULL){
        return;
    }
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    while(!pendingNodes.empty()){
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        if(front == NULL){
            cout<<endl;
            if(pendingNodes.empty()){
                break;
            }
            pendingNodes.push(NULL);
            continue;
        }
        cout<<front->data<<" ";    

        if(front->left){
            pendingNodes.push(front->left);
        }
        if(front->right){
            pendingNodes.push(front->right);
        }
    }
}
    public:
    bool hasData(int data){
        return hasData(root,data);
    }

    void insertData(int data){
        this->root = insertData(root,data);
    }

    void deleteData(int data){
        this->root = deleteData(root,data);
    }

    void printTree(){
        printTree(root);
    }
};