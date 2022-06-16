#include<iostream>
using namespace std;
void keypad(int num , string output , string arr[]){
    if (num == 0){
        cout<<output<<endl;
        return;
    }
    int n1 = num%10;
    string s1 = arr[n1];
    for (int i =0 ; i<s1.size() ;i++){
        keypad(num/10 , s1[i] + output , arr);
    }
}
void helper(int num){
    string output = "";
    string arr[] = {"" , "" , "abc" , "def" , "ghi" , "jkl" ,"mno", "pqrs" , "tuv" ,"wxyz"};
    keypad(num,output,arr);
}
int main(){
    int num;
    cin>>num;
    helper(num);
}