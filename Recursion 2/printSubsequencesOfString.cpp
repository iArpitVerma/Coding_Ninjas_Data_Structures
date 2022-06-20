#include <iostream>
#include <cmath>
using namespace std;
void printSubsequences(string input, string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    printSubsequences(input.substr(1), output);
    printSubsequences(input.substr(1), output + input[0]);
}
int main(){
    string input;
    cin>>input;
    string output = "";
    printSubsequences(input,output);
}