#include <iostream>
using namespace std;
bool splitArray(int* arr, int n, int lsum = 0, int rsum = 0){
    if(n==0){
        return lsum == rsum;
    }

    if(arr[0]%5 == 0){
        lsum += arr[0];
    }
    else if(arr[0]%3 == 0){
        rsum += arr[0];
    }
    else{
        return splitArray(arr+1,n-1,lsum+arr[0],rsum) || splitArray(arr+1,n-1,lsum,rsum+arr[0]);
    }
    return(arr+1,n-1,lsum,rsum);

}
int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(splitArray(arr,n)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}