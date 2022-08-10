#include <iostream>
using namespace std;
// Brute Force - O(3^n)
int editDistance(string s, string t){
    if(s.size() == 0 || t.size() == 0){
        return max(s.size(),t.size());
    }
    if(s[0] == t[0]){
        return editDistance(s.substr(1),t.substr(1));
    }else{
        // Insert
        int a = 1 + editDistance(s.substr(1),t);
        // Delete
        int b = 1 + editDistance(s,t.substr(1));
        // Replace 
        int c = 1 + editDistance(s.substr(1),t.substr(1));

        return min(a,min(b,c));
    }
}

// Memoization - O(m*n)
int editDistance1(string s, string t,int** output){
    int m = s.size();
    int n = t.size();
    if(s.size() == 0 || t.size() == 0){
        return max(s.size(),t.size());
    }

    if(output[m][n] != -1){
        return output[m][n];
    }
    int ans;
    if(s[0] == t[0]){
        ans = editDistance1(s.substr(1),t.substr(1),output);
    }else{
        // Insert
        int a = 1 + editDistance1(s.substr(1),t,output);
        // Delete
        int b = 1 + editDistance1(s,t.substr(1),output);
        // Replace 
        int c = 1 + editDistance1(s.substr(1),t.substr(1),output);

        ans = min(a,min(b,c));
    }

    output[m][n] = ans;
    return ans;

}

// DP - O(m*n)
int editDistance2(string s, string t){
    int m = s.size();
    int n = t.size();
    int** output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i] = new int[n+1];
    }
    
    // Fill 1st Row
    for(int i=0;i<=n;i++){
        output[0][i] = i;
    }

    // Fill 1st Column
    for(int i=1;i<=m;i++){
        output[i][0] = i;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i] == t[n-j]){
                output[i][j] = output[i-1][j-1];
            }else{
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];

                output[i][j] = min(a,min(b,c)) + 1;
            }
        }
    }

    return output[m][n];
}
int main(){
    string s,t;
    cin>>s>>t;
    int** output = new int*[s.size()+1];
    for(int i=0;i<s.size()+1;i++){
        output[i] = new int[t.size()+1];
        for(int j=0;j<t.size()+1;j++){
            output[i][j] = -1;
        }
    }
    cout<<editDistance2(s,t)<<endl;
    cout<<editDistance1(s,t,output)<<endl;
    cout<<editDistance(s,t)<<endl;
}