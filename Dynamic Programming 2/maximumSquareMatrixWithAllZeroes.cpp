#include <iostream>
using namespace std;
int maxSquareMatrixSize(int** arr, int n, int m){
    int output[n][m];
    int maxSize = 0;

    // Fill 1st Row
    for(int j=0;j<m;j++){
        if(arr[0][j] == 0){
            output[0][j] = 1;
            maxSize = 1;
        }else{
            output[0][j] = 0;
        } 
    }

    // Fill 1st Column
    for(int i=0;i<n;i++){
        if(arr[i][0] == 0){
            output[i][0] = 1;
            maxSize = 1;
        }else{
            output[i][0] = 0;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j] == 1){
                output[i][j] = 0;
            }else{
                output[i][j] = 1 + min(output[i-1][j-1] , min(output[i-1][j], output[i][j-1]));
            }
                maxSize = max(maxSize,output[i][j]);
        }
    }
    return maxSize;
}
int main(){
    int n,m;
    cin>>n>>m;
    int**arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<maxSquareMatrixSize(arr,n,m)<<endl;
}