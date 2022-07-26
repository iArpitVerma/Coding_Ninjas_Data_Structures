#include <iostream>
#include<unordered_map>
using namespace std;
int longestSubset0Sum(int* arr, int n){
    unordered_map<int,int> m;
    int sum = 0;
    int maxLength = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
        if(arr[i] == 0 && maxLength == 0){
            maxLength = 1;
        }
        if(sum == 0){
            maxLength = max(i+1,maxLength);
        }
        if(m.count(sum)){
            int length = i - m[sum];
            maxLength = max(length,maxLength);
            continue;
        }
        m[sum] = i;
    }
    return maxLength;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<longestSubset0Sum(arr,n)<<endl;
}