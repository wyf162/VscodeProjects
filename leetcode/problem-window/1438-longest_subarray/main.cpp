#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> queMax, queMin;
        int n = nums.size();
        int left =0, right=0;
        int ret = 0;
        while (right<n){
            while (!queMax.empty() && queMax.back()<nums[right]){
                queMax.pop_back();
            }
            while (!queMin.empty() && queMin.back()>nums[right]){
                queMin.pop_back();
            }

            queMax.push_back(nums[right]);
            queMin.push_back(nums[right]);
            while (!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front()>limit){
                if (nums[left] == queMin.front()){
                    queMin.pop_front();
                }
                if (nums[left] == queMax.front()){
                    queMax.pop_front();
                }
                left++;
            }
            ret = max(ret, right-left+1);
            right++;
        }
        return ret;
    }
};


int main(){
    vector<int> nums = {8,2,4,7};
    int limit = 4;
    Solution sol;
    int ret;
    ret = sol.longestSubarray(nums, limit);
    cout<<ret<<endl;
}