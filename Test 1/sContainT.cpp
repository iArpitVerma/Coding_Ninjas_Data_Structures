#include <iostream>
using namespace std;
bool sContainT(string s, string t){
    int i=0 , j=0;
    while(i<t.size() && j<s.size()){
        if(i == t.size()-1){
            if(t[i] == s[j]){
                return true;
            }
        }
        else if(t[i] == s[j]){
            i++;
        }
        j++;
    }
    return false;
}
int main(){
    string s , t;
    cin>>s>>t;
    if(sContainT(s,t)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}