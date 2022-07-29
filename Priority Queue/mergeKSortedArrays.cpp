#include <iostream>
#include<queue>
using namespace std;

// One Approach
vector<int> mergeKSortedArrays1(vector<vector<int>> input,int k){

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        for(int j=0;j<input[i].size();j++){
            pq.push(input[i][j]);
        }
    }

    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// Second Approach
class data{
public:
    int element;
    int arrayIndex;
    int elementIndex;

    data(int element, int arrayIndex, int elementIndex){
        this->element = element;
        this->arrayIndex = arrayIndex;
        this->elementIndex = elementIndex;
    }
};

struct mycomp
{
    bool operator()(data &d1, data &d2){
        return d1.element > d2.element;
    }
};

vector<int> mergeKSortedArrays2(vector<vector<int>> input,int k){
    vector<int> ans;
    priority_queue<data,vector<data>,mycomp> pq;
    for(int i=0;i<k;i++){
        data d(input[i][0],i,0);
        pq.push(d);
    }

    while(!pq.empty()){
        data curr = pq.top();
        pq.pop();
        ans.push_back(curr.element);
        int arrayIndex = curr.arrayIndex;
        int elementIndex = curr.elementIndex;
        if(elementIndex+1 < input[arrayIndex].size()){
            data d(input[arrayIndex][elementIndex+1],arrayIndex,elementIndex+1);
            pq.push(d);
        }
    }
    return ans;
}

int main(){
    int k;
    cin>>k;    
    vector<vector<int>> v(k);
    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        for(int j= 0;j<n;j++){
            int val;
            cin>>val;
            v[i].push_back(val);
        }
    }
    vector<int> output = mergeKSortedArrays2(v,k);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
}