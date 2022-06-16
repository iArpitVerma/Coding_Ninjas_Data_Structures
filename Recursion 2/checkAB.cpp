#include <iostream>
using namespace std;
bool checkAB(string s,int n){
    if(s.empty()){
        return true;
    }

    if(s.size() == n){
        if(s[0] != 'a'){
            return false;
        }
    }
    if(s[0] == 'a'){
        if(s[1] == 'b'&& s[2] == 'b'){
            s = s.substr(2);
        }
        else if(s[1] == '\0'){
            return true;
        }
        else{
            return false; 
        }
    }
    if(s[0] == 'b'){
        if(s[1] == 'a'){
            s= s.substr(1);
        }
        else if(s[1] == '\0'){
            return true;
        }
        else{
            return false;
        }

    }
    return checkAB(s,n);
}
int main(){
    string s;
    cin>>s;
    if(checkAB(s,s.size()) == 1){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}