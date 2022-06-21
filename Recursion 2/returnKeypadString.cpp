#include <iostream>
#include<cstring>
using namespace std;
int keypadString(int num, string* output, string keypad[]){
    int x = num%10;
    if(x==0 || x==1){
        output[0] = "";
        return 1;
    }
    int smallOutputSize = keypadString(num/10,output,keypad);
    for(int i=1;i<keypad[x].size();i++){
        for(int j=0;j<smallOutputSize;j++){
            output[smallOutputSize*i +j] = output[j];
        }
    }

    for(int i=0;i<keypad[x].size();i++){
        for(int j=0;j<smallOutputSize;j++){
            output[smallOutputSize*i + j] = output[smallOutputSize*i + j] +keypad[x][i];
        }
    }

    return smallOutputSize*keypad[x].size();
}
int main(){
    int num;
    cin>>num;
    string * output = new string[1000];
    string keypad[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int numOfStrings = keypadString(num,output,keypad);
    for(int i=0;i<numOfStrings;i++){
        cout<<output[i]<<endl;
    }
}