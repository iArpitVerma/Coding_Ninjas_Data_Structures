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
class stacksUsingLL{
    node<T>* head;
    int size;

    public:
    stacksUsingLL(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void push(T element){
        // inserting element at head always
        // head->30->20->10->NULL 
        node<T>* n1 = new node<T>(element);
        n1->next = head;
        head = n1;
        size++;
    }

    T pop(){
        if(head == NULL){
            return 0;
        }
        node<T>* temp = head;
        T tempData = head->data;
        head = head->next;
        delete temp;
        size--;
        return tempData;
    }

    T top(){
        if(head == NULL){
            return 0;
        }
        return head->data;
    }
};



int main(){
    int t;
    cin>>t;
    stacksUsingLL<int> s;
    while(t--){
        int option;
        cin>>option;
        if(option == 1){
            int data;
            cin>>data;
            s.push(data);
        }
        else if(option == 2){
            cout<<s.pop()<<endl;
        }
        else if(option == 3){
            cout<<s.top()<<endl;
        }
        else if(option == 4){
            cout<<s.getSize()<<endl;
        }
        else if(option == 5){
            if(s.isEmpty()){
                cout<<"true"<<endl;
            }
            else{
                cout<<"false"<<endl;
            }
        }
    }
}