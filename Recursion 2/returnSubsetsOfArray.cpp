#include <iostream>
#include<cmath>
using namespace std;
int subsets(int * input, int n, int output[][20]){
    if(n == 0){
        output[0][0] = 0;
        return 1;
    }

    int smallOutputSize = subsets(input+1,n-1,output);
    for(int i=0;i<smallOutputSize;i++){
        int col = output[i][0] + 1;
        output[i+smallOutputSize][0] = col;
        output[i+smallOutputSize][i] = input[0];
        for(int j=2;j<=col;j++){
            output[i+smallOutputSize][j] = output[i][j-1];
        }
    }
    return 2*smallOutputSize;
}
int main(){
    int n;
    cin>>n;
    int* input = new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int rows = pow(2,n);
    int output[rows][20];
    cout<<subsets(input,n,output)<<endl;
}