#include <bits/stdc++.h>
using namespace std;
int tripletSum(int * arr, int n ,int k){
    sort(arr,arr+n);
    int i,j,count =0,ci, cj;
    for(int l=0;l<n-2;l++){
        int sum = k - arr[l];
        i = l+1,j=n-1;
        while(i<j){
            ci = 1, cj =1 ;
            if(arr[i] + arr[j] == sum){
                count++;
                // Some adjacent elements are equal separated by some non equal elements
                while(arr[i] == arr[i+1] && i<j){
                    ci++, i++;
                }
                while(arr[j] == arr[j-1] && i<j){
                    cj++,j--;
                }
                count = count + ci*cj -1;
                i++,j--;
            }
            else if(arr[i] + arr[j] > sum){
                j--;
            }
            else{
                i++;
            }
        }
    }
    return count;
}
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        int * arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>k;
        cout<<tripletSum(arr,n,k)<<endl;
        delete []arr;
    }
}