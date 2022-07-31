#include <iostream>
#include<queue>
using namespace std;
void printRunningMedian(int arr[], int n){
    // Max PQ | Min PQ
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    for(int i=0;i<n;i++){
        // Pushing elements in heap
        if(i == 0){
            max.push(arr[0]);
        }else{
            if(max.top() < arr[i]){
                min.push(arr[i]);
            }else{
                max.push(arr[i]);
            }
        }

        // keeping size of both heaps equal or difference of 1
        if(int(min.size() - max.size()) > 1){
            max.push(min.top());
            min.pop();
        }else if(int(max.size() - min.size()) > 1){
            min.push(max.top());
            max.pop();
        }

        // checking size to find median
        if(max.size() > min.size()){
            cout<<max.top()<<endl;
        }else if(min.size() > max.size()){
            cout<<min.top()<<endl;
        }else{
            cout<<(min.top() + max.top())/2 <<endl;
        }
    }

    /* min.size() and max.size() both return unsigned int 
    and their diff takes a 2's complement of the second function which is also unsigned and throws a garbage value out of range
    so better typecast into a signed int i.e int
    example : 
    max.size() — min.size()
    which is: 1 — 3
    Since both are unsigned numbers, hence it will be calculated in the machine as:
    1 + ( 2's complement of 3)
    2's complement of 3 will be 18446744073709551613 (Considering unsigned long long)
    Hence answer will be 18446744073709551614
    If you store this number in a long long variable then it will become a signed number. 
    Thus bits that correspond to 18446744073709551614 in unsigned long long will be -2 in signed long long.
    You can understand it by realizing that the machine has the same system for addition and subtraction, be it signed numbers or unsigned numbers. 
    If you want to understand it properly then you will need to study the whole number representation.
    As a good practice, it is better to typecast the operands before doing such operations.
    */
    cout<<"Min PQ size : "<<min.size()<<endl;
    cout<<"Max PQ size : "<<max.size()<<endl;
    int minSize = min.size();
    int maxSize = max.size();
    cout<<"Signed diff : "<<minSize - maxSize<<endl;
    cout<<"Unsigned diff : "<<min.size() - max.size()<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printRunningMedian(arr,n);
}