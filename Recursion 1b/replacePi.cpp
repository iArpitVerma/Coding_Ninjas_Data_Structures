#include <iostream>
#include<cstring>
using namespace std;
void shifting(char * arr , int n){
    arr[n+2] ='\0';
    for(int i=n+1;i>3;i--){
        arr[i] = arr[i-2];
    }
}
void replacePi(char * arr, int n){
    if(n<=1){
        return;
    }
    if(arr[0] == 'p' && arr[1] == 'i'){
        shifting(arr,n);
        arr[0] = '3' , arr[1] = '.', arr[2] = '1', arr[3] = '4' ;
        arr = arr + 3;
        n = n + 2;
    }
    replacePi(arr+1,n-1);
}
int main(){
    char * arr = new char[1000];
    cin>>arr;
    replacePi(arr,strlen(arr));
    cout<<arr<<endl;
    delete []arr;
}