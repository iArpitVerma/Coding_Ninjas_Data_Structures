#include <iostream>
#include<cmath>
using namespace std;
void printSubsets(int input[],int n, int output[],int m){
    if(n==0){
        for(int i=0;i<m;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printSubsets(input+1,n-1,output,m);
    output[m] = input[0];
    printSubsets(input+1,n-1,output,m+1);
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int k = pow(2,n);
    int output[k];
    printSubsets(input,n,output,0);
}