#include <iostream>
using namespace std;
int main(){
    int rows;
    cin>>rows;
    int ** p = new int* [rows];
    for(int i=0;i<rows;i++){
        p[i] = new int [i+1];
        for(int j=0;j<i+1;j++){
            cin>>p[i][j];
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<i+1;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<rows;i++){
        delete [] p[i];
    }
    delete [] p;
}