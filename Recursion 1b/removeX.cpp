#include <iostream>
#include<cstring>
using namespace std;
void removeX(char * arr,int n){
    if(n==0){
        return;
    }
    removeX(arr+1,n-1);
    if(arr[0] == 'x'){
        for(int i=0;i<n;i++){
            arr[i] = arr[i+1];
        }
    }
}
int main(){
    char * arr = new char [1000];
    cin>>arr;
    removeX(arr,strlen(arr));
    cout<<arr<<endl;
}