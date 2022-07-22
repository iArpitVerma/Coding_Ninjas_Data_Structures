#include<vector>
#include<queue>
using namespace std;
template <typename T>
class treeNode{
    public:
    T data;
    vector<treeNode<T>*> children;

    treeNode(T data){
        this->data = data;
    }

    ~treeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
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

void printNodeLevelWise(treeNode<int>* root){
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<" : ";
        for(int i=0;i<front->children.size();i++){
            treeNode<int>* child = front->children[i];
            pendingNodes.push(child);
            if(i == front->children.size() - 1){
                cout<<child->data;
            }else{
                cout<<child->data<<",";
            }
        }
        cout<<endl;    
    }
}