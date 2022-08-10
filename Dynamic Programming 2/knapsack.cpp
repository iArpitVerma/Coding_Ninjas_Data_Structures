#include <iostream>
using namespace std;
// Brute Force - O(2^n)
int knapsack(int* weights, int* val, int maxWeight, int n){
    if(n == 0 || maxWeight == 0){
        return 0;
    }
    if(maxWeight < weights[0]){
        return knapsack(weights+1,val+1,maxWeight,n-1);
    }
    int x = val[0] +  knapsack(weights+1,val+1,maxWeight-weights[0],n-1);
    int y = knapsack(weights+1,val+1,maxWeight,n-1);

    return max(x,y);
}

// Memoization - O(n*maxWeight)
int knapsack1(int* weights, int* val, int maxWeight, int n, int** output){
    if(n == 0 || maxWeight == 0){
        return 0;
    }

    if(output[n][maxWeight] != -1){
        return output[n][maxWeight];
    }
    if(maxWeight < weights[0]){
        output[n][maxWeight] = knapsack1(weights+1,val+1,maxWeight,n-1,output);
    }
    else{
        int x = val[0] +  knapsack1(weights+1,val+1,maxWeight-weights[0],n-1,output);
        int y = knapsack1(weights+1,val+1,maxWeight,n-1,output);

        output[n][maxWeight] = max(x,y);
    }
    return output[n][maxWeight];
}

// DP
int knapsack2(int* weights, int* val, int maxWeight, int n){
    int** output = new int*[n+1];
    for(int i=0;i<=n;i++){
        output[i] = new int[maxWeight+1];
    }

    // Fill 1st Row
    for(int i=0;i<=maxWeight;i++){
        output[0][i] = 0;
    }

    // Fill 1st Column
    for(int j=1;j<=n;j++){
        output[j][0] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxWeight;j++){
            if(weights[i-1] > j){
                output[i][j] = output[i-1][j];
            }else{
                int a = val[i-1] + output[i-1][j-weights[i-1]];
                int b = output[i-1][j];
                output[i][j] = max(a,b);
            }
        }
    }
    return output[n][maxWeight];
}

int main(){
    int n;
    cin>>n;

    int* weights = new int[n];
    int* val = new int[n];
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    for(int j=0;j<n;j++){
        cin>>val[j];
    }
    int maxWeight;
    cin>>maxWeight;
    int** output = new int*[n+1];
    for(int i=0;i<=n;i++){
        output[i] = new int[maxWeight+1];
        for(int j=0;j<maxWeight+1;j++){
            output[i][j] = -1;
        }
    }
    cout<<knapsack(weights,val,maxWeight,n)<<endl;
    cout<<knapsack1(weights,val,maxWeight,n,output)<<endl;
    
}