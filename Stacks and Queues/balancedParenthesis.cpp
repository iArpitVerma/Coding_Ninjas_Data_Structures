#include <iostream>
#include<stack>
using namespace std;
bool checkBalanced(string s){
    stack<char> a;
    for(int i=0;i<s.size();i++){
        if(a.empty()){
            a.push(s[i]);
        }
        else if( (a.top() == '(' && s[i] == ')') ||(a.top() == '{' && s[i] == '}' ) || (a.top() == '[' && s[i] == ']')){
            a.pop();
        }
        else{
            a.push(s[i]);
        }
    }
    if(a.empty()){
        return true;
    }
    return false;
}
int main(){
    string s;
    cin>>s;
    if(checkBalanced(s)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}
