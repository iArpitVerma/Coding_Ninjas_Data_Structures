#include <iostream>
#include<climits>
using namespace std;
template <typename T>
class stacksUsingArrays{
    T* data;
    int nextIndex;
    int capacity;

    public:

    stacksUsingArrays(){
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0 ;
    }

    void push(T element){
        if(nextIndex == capacity){
            // Dynamic Array created
            T* newData = new T[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i] = data[i];
            }
            delete [] data;
            capacity *= 2;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop(){
        if(nextIndex == 0){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top(){
        if(nextIndex == 0){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex - 1];
    }

};

int main(){
    // Using templates
    // stacksUsingArrays<int> s;
    stacksUsingArrays<char> s;
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
}