#include <iostream>
#include<unordered_map>
using namespace std;
int pairSum(int* arr, int n){
    unordered_map<int,int> m;
    int count = 0;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        if(m.count(-arr[i])){
            count = count + m[-arr[i]];
            if(arr[i] == 0){
                count--;
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
    cout<<pairSum(arr,n)<<endl;
}