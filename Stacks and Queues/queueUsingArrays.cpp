#include <iostream>
using namespace std;
template <typename T>
class queueUsingArrays{
    T* data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

    public:
    queueUsingArrays(int s){
        data = new T[s];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }

    T getSize(){
        return size;
    }

    bool empty(){
        return size == 0;
    }   

    void enqueue(T element){
        if(size == 0){
            firstIndex = 0;
        }
        if(size == capacity){
            T* newData = new T[2*capacity];
            int j=0;
            for(int i=firstIndex;i<capacity;i++){
                newData[j++] = data[i]; 
            }
            for(int i=0;i<firstIndex;i++){
                newData[j++] = data[i];
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity = 2*capacity;
        }
        data[nextIndex] = element;
        // For Circular Rotation
        nextIndex = (1+nextIndex)%capacity;
        size++;
    }

    T front(){
        if(size == 0){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue(){
        if(size == 0){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        // For CIrcular Rotation
        firstIndex = (firstIndex + 1)%capacity;
        size--;
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

};
int main(){
    queueUsingArrays<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    
    cout<<q.getSize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(10);
    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.empty()<<endl;
}