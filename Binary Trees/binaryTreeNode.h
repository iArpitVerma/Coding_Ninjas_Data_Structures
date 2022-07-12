#include<queue>
using namespace std;
template <typename T>
class binaryTreeNode{
    public:
    T data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode(){
        delete left;
        delete right;
    }
};

binaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    if(root->data == -1){
        return NULL;
    }    

    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cout<<"Enter left child of "<< front->data<<endl;
        cin>>leftChildData;
        if(leftChildData != -1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        int rightChildData;
        cout<<"Enter right child of "<<front->data<<endl;
        cin>>rightChildData;
        if(rightChildData != -1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;    
}

void printLevelWise(binaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<" : ";
        if(front->left){
            cout<<"L"<<front->left->data<<" ";
            pendingNodes.push(front->left);
        }
        
        if(front->right){
            cout<<"R"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}


void printLevelAtNewLine(binaryTreeNode<int> *root) {
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

