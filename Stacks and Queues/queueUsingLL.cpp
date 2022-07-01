#include <iostream>
using namespace std;
template <typename T>
class node{
    public:
    T data;
    node<T>* next;

    node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class queueUsingLL{
    int size;
    node<T>* head;
    node<T>* tail;

    public:

    queueUsingLL(){
        size =0;
        head = NULL;
        tail = NULL; 
    }

    int getSize(){
        return size;
    }

    bool empty(){
        return size == 0;
    }

    T front(){
        if(head == NULL){
            return 0;
        }
        return head->data;
    }

    void enqueue(T element){
        node<T>* newNode = new node<T>(element);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
        size++;
    }

    T dequeue(){
        if(head == NULL){
            return 0;
        }

        node<T>* temp = head;
        T ans = temp->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};
int main(){
    queueUsingLL<int> q;

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