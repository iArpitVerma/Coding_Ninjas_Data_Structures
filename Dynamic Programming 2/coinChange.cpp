#include <iostream>
using namespace std;
bool coinChange(int n, int x,int y){
    int * arr = new int[n+1];
    arr[0] = false;
    arr[1] = true;
    for(int i=2;i<=n;i++){
        if(i-1>=0 && arr[i-1] == false){
            arr[i] = true;
        }else if(i-x>=0 && arr[i-x] == false){
            arr[i] = true;
        }else if(i-y>=0 && arr[i-y] == false){
            arr[i] = true;
        }else{
            arr[i] = false;
        }
    }
    return arr[n];
}
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    if(coinChange(n,x,y)){
        cout<<"Beerus"<<endl;
    }else{
        cout<<"Whis"<<endl;
    }
}