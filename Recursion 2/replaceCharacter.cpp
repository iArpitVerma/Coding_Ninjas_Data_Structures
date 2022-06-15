#include <iostream>
using namespace std;
void replaceCharacter(char * str, char c1, char c2){
    if(str[0] == '\0'){
        return;
    }
    if(str[0] == c1){
        str[0] = c2;
    }
    replaceCharacter(str+1,c1,c2);
}
int main(){
    char * str = new char[1000];
    cin>>str;
    char c1,c2;
    cin>>c1>>c2;
    replaceCharacter(str,c1,c2);
    cout<<str<<endl;
}