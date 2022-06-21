#include<iostream>
using namespace std;
void printkeypad(int num, string output, string keypad[]){
    int x = num%10;
    if(num == 0){
        cout<<output<<endl;
        return;
    }

    for(int i=0;i<keypad[x].size();i++){
        printkeypad(num/10, keypad[x][i] + output,keypad);
    }
}
int main(){
    int num;
    cin>>num;
    string output = "";
    string keypad[] ={" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    printkeypad(num,output,keypad);
}