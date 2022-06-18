#include <bits/stdc++.h>
using namespace std;
int pairSum(int * arr, int n,int k){
    sort(arr,arr+n);
    int i=0,j=n-1,count =0,ci, cj;
    while(i<j){
        ci = 1, cj =1 ;
        if(arr[i] + arr[j] == k){
            // All remaining elements are equal
            if(arr[i] == arr[j]){
                int m = j-i+1;
                count = count + ((m)*(m-1))/2;
                return count;
            }
            count++;
            // Some elements are equal separated by some non equal element
            while(arr[i] == arr[i+1] && i<j){
                ci++, i++;
            }
            while(arr[j] == arr[j-1] && i<j){
                cj++,j--;
            }
            count = count + ci*cj -1;
            i++,j--;
        }
        else if(arr[i] + arr[j] > k){
            j--;
        }
        else{
            i++;
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
        cout<<pairSum(arr,n,k)<<endl;
        delete []arr;
    }
}