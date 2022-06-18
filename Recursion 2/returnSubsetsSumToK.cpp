#include <iostream>
#include<cmath>
using namespace std;
int subsetsSumToK(int input[],int n,int k){
    if(n==0){
        if(k==0){
            return 1;
        }
        return 0;
    }

    int s1 = subsetsSumToK(input+1,n-1,k);
    int s2 = subsetsSumToK(input+1,n-1,k-input[0]);
    return s1 + s2;
}
int main(){
    int n,k;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }    
    cin>>k;
    cout<<subsetsSumToK(input,n,k)<<endl;
}