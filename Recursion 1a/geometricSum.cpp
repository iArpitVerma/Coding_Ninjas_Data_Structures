#include <iostream>
#include<cmath>
using namespace std;
float geometricSum(int n){
    if(n==0){
        return 1;
    }
    return geometricSum(n-1) + (1/pow(2,n));
}
int main(){
    int n;
    cin>>n;
    cout<<geometricSum(n)<<endl;
}