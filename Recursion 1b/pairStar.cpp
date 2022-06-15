#include <iostream>
#include<cstring>
using namespace std;
void pairStar(char * str,int n){
    if(n == 1){
        return;
    }
    if(str[0] == str[1]){
        for(int i=n+1;i>1;i--){
            str[i] = str[i-1];
        }
        str[1] = '*';
        str = str+1;
    }
    pairStar(str+1,n-1);
}
int main(){
    char * str = new char[1000];
    cin>>str;
    pairStar(str,strlen(str));
    cout<<str<<endl;
}