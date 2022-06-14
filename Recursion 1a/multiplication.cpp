#include <iostream>
using namespace std;
int multiplication(int m,int n){
    if(n==0){
        return 0;
    }
    int ans = multiplication(m,n-1);
    return ans + m;
}
// Another Method
int multiplication1(int m,int n,int ans =0){
    if (n==0){
        return ans;
    }
    ans = ans +m;
    multiplication1(m,n-1,ans);
}

int main(){
    int m,n;
    cin>>m>>n;
    cout<<multiplication(m,n)<<endl;
}