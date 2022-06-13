#include <iostream>
using namespace std;
int print1ToN(int n){
    if(n==1){
        cout<<1<<" ";
        return 1;
    }
    int num = 1 + print1ToN(n-1);
    cout<<num<<" ";
    return num;
}
int main(){
    int n;
    cin>>n;
    print1ToN(n);
}