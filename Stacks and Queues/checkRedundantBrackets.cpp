#include <iostream>
#include<stack>
using namespace std;
bool isRedundant(string s){
    stack<char> t;
    int i =0;
    while(i<s.size()){
            int count = 0;
            while(s[i]!=')' && i!=s.size()){
                t.push(s[i]);
                i++;
            }
            i--;
            while(s[i]!='(' && i>=0){
                t.pop();
                count++;
                i--;
            }
            t.pop();
            if(count <=1 ){
                return true;
            }else{
                i = i + 2 + count; 
            }
    }   
    
    return false;       
}
int main(){
    string s;
    cin>>s;
    if(isRedundant(s)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}