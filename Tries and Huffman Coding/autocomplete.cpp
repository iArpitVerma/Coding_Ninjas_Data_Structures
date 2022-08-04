#include<iostream>
#include<vector>
using namespace std;
class trieNode{
public:
    char data;
    trieNode **children;
    bool isTerminal;

    trieNode(char data){
        this->data = data;
        children = new trieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
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
            root->isTerminal = true;
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

    void printPossibleWords(trieNode* root, string word){
        if(root->isTerminal == true){
            cout<<word<<endl;
        }
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                char c = i + 'a';
                printPossibleWords(root->children[i],word + c);
            }
        }
    }
    void autoComplete(vector<string> v, string pattern){
        // Build a trie
        for(int i=0;i<v.size();i++){
            insertWord(v[i]);
        }

        // Search in trie
        if(searchWord(pattern) == false){
            return;
        }

        string s = pattern;

        while(pattern.size() != 0){
            int index = pattern[0] - 'a';
            root = root->children[index];
            pattern = pattern.substr(1);
        }

        printPossibleWords(root,s);
    }
};
int main(){
    trie t;
    int n;
    cin >> n;
    vector<string> vect;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    string pattern;
    cin >> pattern;
    t.autoComplete(vect, pattern);
}