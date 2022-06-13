#include <iostream>
#include<cstring>
using namespace std;
void input(int * p,int n){
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
}
bool checkNumber(int *p,int n,int x){
    if(n==1){
        return (p[0] == x)?true:false ; 
    }
    if(p[0]==x){
        return true;
    }
    checkNumber(p+1,n-1,x);
}
int main(){
    int n,x;
    cin>>n;
    int * p = new int [n];
    input(p,n);
    cin>>x;
    if(checkNumber(p,n,x) == 1){
       cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}