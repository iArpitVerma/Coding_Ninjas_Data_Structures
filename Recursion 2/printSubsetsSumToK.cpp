#include <iostream>
using namespace std;
void printSubsets(int input[],int n,int k,int output[],int m){
    if(n==0){
        if(k==0){
            for(int i=0;i<m;i++){
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    printSubsets(input+1,n-1,k,output,m);
    output[m] = input[0];
    printSubsets(input+1,n-1,k-input[0],output,m+1);

}
int main(){
    int n,k,m=0;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cin>>k;
    int output[n];
    printSubsets(input,n,k,output,m);
}