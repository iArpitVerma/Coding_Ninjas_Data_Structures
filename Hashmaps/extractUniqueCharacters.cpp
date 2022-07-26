#include <iostream>
#include<unordered_map>
using namespace std;
string uniqueCharacters(string s){
    string newString;
    unordered_map<int,int> m;
    for(int i=0;i<s.size();i++){
        if(m.count(s[i])){
            continue;
        }        
        newString.push_back(s[i]);
        m[s[i]] = 1;
    }
    return newString;
}
int main(){
    string s;
    cin>>s;
    cout<<uniqueCharacters(s)<<endl;
}