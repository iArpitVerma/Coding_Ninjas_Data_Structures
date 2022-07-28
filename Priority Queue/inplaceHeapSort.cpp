#include <iostream>
using namespace std;
// Inplace means no extra space is used as we are swapping in the same array 
// but in min/maxPqClass we used a vector pq pf size n
void heapSort(int pq[], int n){
    // insert - Upheapify
    for(int i=1;i<n;i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (i-1)/2;
            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    // remove - Downheapify
    int size = n;
    while(size > 1){
        int temp = pq[0];
        pq[0] = pq[size-1];
        pq[size -1] = temp;
        size--;

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        while(leftChildIndex < size){
            int minIndex = parentIndex;
            if(pq[leftChildIndex] < pq[minIndex]){
                minIndex =leftChildIndex;
            }
            if(rightChildIndex < size && pq[rightChildIndex] <pq[minIndex]){
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex){
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    heapSort(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}