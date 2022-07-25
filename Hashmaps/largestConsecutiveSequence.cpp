#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

void largestConsecutiveSequence(int* arr, int n){
    unordered_map<int,bool> m;
    unordered_map<int,int> index;
    for(int i=0;i<n;i++){
        m[arr[i]] = true;
        if(index.count(arr[i]) == 0){
            index[arr[i]] = i;
        }
    }
    int maxLength = 0, start = INT_MIN;
    for(int i=0;i<n;i++){
        if(m[arr[i]] == false){
            continue;
        }
        int j = arr[i] ; int nstart = arr[i], size = 1;
        while(m.count(j)> 0 && m[j] ==  true){
            size++;
            j++;
            m[j] = false;
        }
        j = arr[i]-1;
        while(m.count(j)>0 && m[j] == true){
            size++;
            nstart--;
            j--;
            m[j] = false;
        }
        if(size > maxLength ){
            maxLength = size;
            start = nstart;
        }else if( size == maxLength){
            if(index[start] >index[nstart]){
                start = nstart;
            }
        }
        
        cout<<start<<" "<<maxLength<<endl;
                
    }

    cout<<start<<" "<<start+maxLength-1<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    largestConsecutiveSequence(arr,n);
}