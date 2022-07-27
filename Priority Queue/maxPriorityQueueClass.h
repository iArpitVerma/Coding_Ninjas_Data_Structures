#include<vector>
using namespace std;
class priorityQueue{
    vector<int> pq;
public:
    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;

            if(pq[childIndex] > pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }else{
                break;
            }

            childIndex = parentIndex;

        }
    }

    int removeMax(){
        if(isEmpty()){
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;

        while(leftChildIndex < pq.size()){
            int maxIndex = parentIndex;
            if(pq[leftChildIndex] > pq[maxIndex]){
                maxIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[rightChildIndex] > pq[maxIndex]){
                maxIndex = rightChildIndex;
            }
            if(pq[maxIndex] > pq[parentIndex]){
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[maxIndex];
                pq[maxIndex] = temp;
            }else{
                break;
            }

            parentIndex = maxIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        } 
        return ans;
    }
};