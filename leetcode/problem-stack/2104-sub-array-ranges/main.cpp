#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  long long subArrayRanges(vector<int> &nums) {
    int n = nums.size();
    vector<int> min_left(n), min_right(n), max_left(n), max_right(n);
    stack<int> min_stack, max_stack;
    for (int i = 0; i < n; i++) {
        while(!min_stack.empty() && nums[min_stack.top()]>nums[i]){
            min_stack.pop();
        }
        min_left[i] = min_stack.empty() ? -1:min_stack.top();
        min_stack.push(i);

        while(!max_stack.empty() && nums[max_stack.top()]<=nums[i]){
            max_stack.pop();
        }
        max_left[i] = max_stack.empty()?-1:max_stack.top();
        max_stack.push(i);
    }
    min_stack = stack<int>();
    max_stack = stack<int>();
    for(int i=n-1;i>=0;i--){
        while(!min_stack.empty() && nums[min_stack.top()]>=nums[i]){
            min_stack.pop();
        }
        min_right[i] = min_stack.empty() ? n:min_stack.top();
        min_stack.push(i);
        while(!max_stack.empty() && nums[max_stack.top()]<nums[i]){
            max_stack.pop();
        }
        max_right[i] = max_stack.empty() ? n:max_stack.top();
        max_stack.push(i);
    }
    long long sum_max=0, sum_min=0;
    for (int i=0;i<n;i++){
        sum_max += static_cast<long long>(max_right[i]-i)*(i-max_left[i])*nums[i];
        sum_min += static_cast<long long>(min_right[i]-i)*(i-min_left[i])*nums[i];
    }
    return sum_max-sum_min;
  }
};


int main(){
    vector<int> nums{1,2,3};
    Solution sol;
    long long ret = sol.subArrayRanges(nums);
    cout<<ret<<endl;
    return 0;
}