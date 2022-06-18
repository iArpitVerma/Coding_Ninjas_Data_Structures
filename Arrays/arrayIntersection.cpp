#include <bits/stdc++.h>
using namespace std;
void intersection(int* arr1, int* arr2,int n,int m){
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int i=0 ,j=0;
    while(i<n && j<m){
        if(arr1[i] == arr2[j]){
            cout<<arr1[i]<<" ";
            i++,j++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            i++;
        }        
    }
    cout<<endl;

}
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        int * arr1 = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        cin>>m;
        int * arr2 = new int[m];
        for(int j=0;j<m;j++){
            cin>>arr2[j];
        }
        intersection(arr1,arr2,n,m);
        delete []arr1;
        delete []arr2;
    }
}