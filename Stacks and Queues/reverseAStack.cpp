#include <iostream>
using namespace std;
#include<stack>

void reverse(stack<int> &s1, stack<int> &s2){
    if(s1.size() == 1 || s1.size() == 0){
        return;
    }

    int x = s1.top();
    s1.pop();
    reverse(s1,s2);
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}
int main(){
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    stack<int> s2;
    reverse(s1,s2);

    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }

}