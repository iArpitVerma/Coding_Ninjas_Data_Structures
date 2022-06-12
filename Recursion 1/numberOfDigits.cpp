#include <iostream>
using namespace std;
int numberOfDigits(int n){
    if(n/10 == 0){
        return 1;
    }
    return 1 + numberOfDigits(n/10);
}
int main(){
    int n;
    cin>>n;
    cout<<numberOfDigits(n)<<endl;
}