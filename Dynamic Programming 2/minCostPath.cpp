#include <iostream>
#include<vector>
#include<climits>
using namespace std;
// Brute Force - O(3^n)
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

// Memoization - o(m*n)
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

// DP - O(m*n)
int minCostPath2(vector<vector<int>> input, int m, int n){
    int** output = new int*[m];
    for(int i=0;i<m;i++){
        output[i] = new int[n];
    }

    // Fill the last cell
    output[m-1][n-1] = input[m-1][n-1];

    // Fill the last column 
    for(int i=m-2;i>=0;i--){
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }

    // Fill the last row
    for(int i=n-2;i>=0;i--){
        output[m-1][i] = output[m-1][i+1] + input[m-1][i];
    }

    // Fill the remaining ones
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j] = input[i][j] + min(output[i+1][j], min(output[i][j+1],output[i+1][j+1]));
        }
    }

    return output[0][0];
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
    cout<<minCostPath2(input,m,n);
}