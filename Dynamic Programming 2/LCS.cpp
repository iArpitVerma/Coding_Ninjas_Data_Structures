// Longest Common Subsequence
#include <iostream>
using namespace std;
// Brute Force - O(2^n) 
int lcs(string s, string t){
    if(s.size() == 0 || t.size() == 0){
        return 0;
    }

    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1),t.substr(1));
    }else{
        int a = lcs(s,t.substr(1));
        int b = lcs(s.substr(1),t);
        // This call (int c)can be ignored
        int c = lcs(s.substr(1),t.substr(1));

        return max(a,max(b,c));
    }
}

// Memoization - O(m*n)
int lcs1(string s, string t, int** output){
    int m = s.size();
    int n = t.size();
    if(s.size() == 0 || t.size() == 0){
        return 0;
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }

    int ans;
    if(s[0] == t[0]){
        ans = 1 + lcs1(s.substr(1),t.substr(1),output);
    }else{
        int a = lcs1(s,t.substr(1),output);
        int b = lcs1(s.substr(1),t,output);
        int c = lcs1(s.substr(1),t.substr(1),output);
        ans = max(a,max(b,c));
    }

    output[m][n] = ans;
    return ans;
}

// DP - O(m*n)
int lcs2(string s, string t){
    int m = s.size();
    int n = t.size();
    int** output = new int*[m+1];
    for(int i=0;i<m+1;i++){
        output[i] = new int[n+1];
    }        

    // Fill 1st row
    for(int i=0;i<=n;i++){
        output[0][i] = 0;
    }

    // Fill 1st column
    for(int i=0;i<=m;i++){
        output[i][0] = 0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i] == t[n-j]){
                output[i][j] = 1 + output[i-1][j-1];
            }else{
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];
                output[i][j] = max(a,max(b,c));
            }
        }
    }

    return output[m][n];
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<endl;
    int** output = new int*[s.size()+1];
    for(int i=0;i<s.size()+1;i++){
        output[i] = new int[t.size()+1];
    }
    for(int i=0;i<s.size()+1;i++){
        for(int j=0;j<t.size()+1;j++){
            output[i][j] = -1;
        }
    }
    cout<<lcs1(s,t,output)<<endl;
    cout<<lcs2(s,t);
}