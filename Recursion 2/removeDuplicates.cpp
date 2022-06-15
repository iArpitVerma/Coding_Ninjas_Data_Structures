#include <iostream>
using namespace std;
void removeDuplicates(char * str){
    if(str[0] == '\0' || str[1] == '\0'){
        return;
    }
    if(str[0] == str[1]){
        for(int i=1;str[i]!='\0';i++){
            str[i] = str[i+1]; 
        }
        str = str - 1;
    }
    removeDuplicates(str+1);
}
int main(){
    char * str = new char[1000];
    cin>>str;
    removeDuplicates(str);
    cout<<str<<endl;
}