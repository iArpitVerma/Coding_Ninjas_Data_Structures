#include <iostream>
#include<unordered_map>
using namespace std;
int pairsWithDiffK(int* arr, int n,int k){
    unordered_map<int,int> m;
    int count = 0;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(k==0){
            int k = m[arr[i]];
            count+= ((k-1)*(k))/2;
            m[arr[i]] = 0;
        }
        else if(m.count(arr[i] - k)){
            if(m[arr[i]-k] != 0){
                count += m[arr[i]] * m[arr[i]-k];
                m[arr[i]] = 0;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<pairsWithDiffK(arr,n,k);
}