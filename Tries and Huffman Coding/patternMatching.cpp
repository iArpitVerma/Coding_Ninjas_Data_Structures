#include <iostream>
#include<vector>
using namespace std;
class trieNode{
public:
    char data;
    trieNode **children;

    trieNode(char data){
        this->data = data;
        children = new trieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};


class trie{
    trieNode* root;

public:
    trie(){
        root = new trieNode('\0');
    }

    void insertWord(trieNode* root,string word){
        // Base Case
        if(word.size() == 0){
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        trieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive Call
        insertWord(child,word.substr(1));
    }

    void insertWord(string word){
        insertWord(root,word);
    }

    bool searchWord(trieNode* root,string word){
        // Base Case
        if(word.size() == 0){
            return true;
        }

        // Small Calculation
        int index = word[0] - 'a';
        trieNode* child;
        if(root->children[index] == NULL){
            return false;
        }else{
            child = root->children[index];
        }

        // Recursive Call
        return searchWord(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchWord(root,word);
    }

    bool patternMatching(vector<string> v, string s){
        for(int i=0;i<v.size();i++){
            while(v[i].size() != 0){
                insertWord(v[i]);
                v[i] = v[i].substr(1);
            }
        }
        return searchWord(s);
    }
};

int main(){
    int n;
    cin>>n;
    vector<string> v;
    while(n--){
        string temp;
        cin>>temp;
        v.push_back(temp);
    }
    string pattern;
    cin>>pattern;
    trie t;
    if(t.patternMatching(v,pattern)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}