#include <iostream>
using namespace std;
int sumOfArray(int * p ,int n,int sum=0){
    if(n==1){
        return sum + p[0];
    }
    sum = sum + p[0];
    sumOfArray(p+1,n-1,sum);
}
int main(){
    int n;
    cin>>n;
    int* p = new int[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<sumOfArray(p,n)<<endl;
    delete []p;
}