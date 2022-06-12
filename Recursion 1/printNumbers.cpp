#include <iostream>
using namespace std;
int print1ToN(int n){
    if(n==1){
        cout<<1<<" ";
        return 1;
    }
    cout<<1 + print1ToN(n-1)<<" ";
    return 1 + print1ToN(n-1);
}
int main(){
    int n;
    cin>>n;
    print1ToN(n);
}