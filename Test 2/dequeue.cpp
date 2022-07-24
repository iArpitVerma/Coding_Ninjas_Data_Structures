#include <iostream>
#include<queue>
using namespace std;
class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
    }
};
class Dequeue{
public:
    int size;
    node* head;
    node* tail;
    Dequeue(int size){
        this->size = size;
        head = NULL;
        tail = NULL;
    }
    void insertFront(int data){
        if(size == 10){
            cout<<"-1"<<endl;
            return;
        }
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insertRear(int data){
        if(size == 10){
            cout<<"-1"<<endl;
            return;
        }
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void deleteFront(){
        if(size == 0){
            cout<<"-1"<<endl;
            return;
        }
        node* temp = head;
        if(head->next == NULL){
            head = NULL;
            tail= NULL;
        }
        head = head->next;
        delete temp;
        size--;
    }
    void deleteRear(){
        if(size == 0){
            cout<<"-1"<<endl;
            return;
        }
        node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        node* a = tail;
        tail = temp;
        delete a;
        size--;
    }
    int getFront(){
        if(head == NULL){
            return -1;
        }
        return head->data;
    }
    int getRear(){
        if(tail == NULL){
            return -1;
        }
        return tail->data;
    }
};
int main(){
    Dequeue q(0);
    cout<<q.getFront()<<endl;
    q.insertFront(49);
    q.insertFront(64);
    q.insertRear(99);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
}