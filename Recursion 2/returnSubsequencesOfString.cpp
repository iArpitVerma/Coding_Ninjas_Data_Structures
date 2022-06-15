#include <iostream>
#include<cmath>
using namespace std;
int subsequences(string input, string * output){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    int smallOutputSize = subsequences(input.substr(1),output); 
    for(int i=0;i<smallOutputSize;i++){
        output[smallOutputSize + i] = input[0] + output[i];
    }   
    return 2*smallOutputSize;
}
int main(){
    string input;
    cin>>input;
    int length = pow(2,input.size());
    string* output = new string[length];
    int count  = subsequences(input,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
}