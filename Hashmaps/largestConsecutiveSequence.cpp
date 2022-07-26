#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> largestConsecutive(vector<int> nums){
    unordered_set<int> s;
    unordered_map<int,int> elementIndex;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
        elementIndex[nums[i]] = i;
    }
    int maxLength = 0;
    int start = -1;
    int index = 0;
    for(int i=0;i<nums.size();i++){
        if(s.count(nums[i] - 1)){
            continue;
        }
        int nstart = nums[i];
        int j = 1;
        while(s.count(nums[i] + j)){
            j++;
        }
        if(j>maxLength){
            maxLength = j;
            start = nstart;
        }else if(j == maxLength){
            if(elementIndex[start] > elementIndex[nstart]){
                start = nstart;
            }
        }
    }
    vector<int> v;
    v.push_back(start);
    v.push_back(start+maxLength-1);
    return v;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<int> a = largestConsecutive(v);
    for(int i=0;i<2;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}