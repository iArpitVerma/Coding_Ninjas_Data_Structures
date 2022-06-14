#include <iostream>
#include<cstring>
using namespace std;
bool checkPalidrome(char * arr, int start,int end ){
    if(start>=end){
        return true;
    }
    if(arr[start] != arr[end]){
        return false;
    }
    checkPalidrome(arr,start+1,end-1);
}
void helper(char * arr){
    int start = 0;
    int end = strlen(arr) - 1;
    if(checkPalidrome(arr,start,end)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}
int main(){
    char * arr = new char[1000];
    cin>>arr;
    helper(arr);
}