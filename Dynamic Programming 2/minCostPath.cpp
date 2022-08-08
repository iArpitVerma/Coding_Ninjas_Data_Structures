#include <iostream>
#include<vector>
#include<climits>
using namespace std;
// Brute Force
int minCostPath(vector<vector<int>> input,int m,int n, int i, int j){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i>=m || j >= n){
        return INT_MAX;
    }
    int x = minCostPath(input,m,n,i,j+1);
    int y = minCostPath(input,m,n,i+1,j);
    int z = minCostPath(input,m,n,i+1,j+1);

    return input[i][j] + min(x,min(y,z));
}

// Memoization
int minCostPath1(vector<vector<int>> input, int m,int n, int i, int j,vector<vector<int>> output){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i>=m || j >= n){
        return INT_MAX;
    }

    if(output[i][j]!=-1){
        return output[i][j];
    }

    int x = minCostPath1(input,m,n,i,j+1,output);
    int y = minCostPath1(input,m,n,i+1,j,output);
    int z = minCostPath1(input,m,n,i+1,j+1,output);

    int ans = input[i][j] + min(x,min(y,z));
    output[i][j] = ans;

    return ans;
}

// DP
int minCostPath2(vector<vector<int>> input, int m, int n,int i, int j){
    
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> input(m);
    int val;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>val;
            input[i].push_back(val);
        }
    }
    cout<<minCostPath(input,m,n,0,0)<<endl;
    vector<vector<int>> output(m,vector<int> (n,-1));
    cout<<minCostPath1(input,m,n,0,0,output)<<endl;
}