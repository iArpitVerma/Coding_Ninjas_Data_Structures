#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;
int stringToInteger(char * arr, int n){
    if(n==0){
        return 0;
    }
    int a = arr[0] - '0';
    return a*pow(10,n-1) + stringToInteger(arr+1,n-1);
}
int main(){
    char * arr = new char [1000];
    cin>>arr;
    cout<<stringToInteger(arr,strlen(arr))<<endl;
}