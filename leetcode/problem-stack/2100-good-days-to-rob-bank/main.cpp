#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int n = security.size();
    vector<int> min_left(n), min_right(n);
    stack<int> min_stack;
    for (int i = 0; i < n; i++) {
        while(!min_stack.empty() && security[min_stack.top()]<security[i]){
            min_stack = stack<int>();
        }
        min_left[i] = min_stack.size();
        min_stack.push(i);
    }
    min_stack = stack<int>();
    for(int i=n-1;i>=0;i--){
        while(!min_stack.empty() && security[min_stack.top()]<security[i]){
            min_stack = stack<int>();
        }
        min_right[i] = min_stack.size();
        min_stack.push(i);
    }
    vector<int> ret;
    for(int i=0;i<n;i++){
        if (min_left[i]>=time && min_right[i]>=time){
            ret.emplace_back(i);
        }
    }
    return ret;
    }
};


int main(){
    Solution sol;
    // vector<int> security={3,1,20,17,26,0,2,29,24};
    // int time=3;
    vector<int> security={5,3,3,3,5,6,2};
    int time=2;
    vector<int> days = sol.goodDaysToRobBank(security, time);
    for(auto day:days){
        cout<<day<<" ";
    }
}
