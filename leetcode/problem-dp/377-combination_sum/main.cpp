#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, 0);
        for (auto &num:nums){
            if (num<=n){
                dp[num] = 1;
            }
        }
        for (int i=1;i<=target;i++){
            for (int j=1;j<i;j++){
                if (find(nums.begin(), nums.end(), j)!=nums.end()){
                    dp[i] += dp[i-j];
                }
            }
        }
        for(auto &d:dp){
            cout<<d<<" ";
        }
        cout<<endl;
        return dp[target];
    }
};


int main(){
    vector<int> nums = {1,2,3};
    int target = 4;
    Solution sol;
    int ret;
    ret = sol.combinationSum4(nums, target);
    cout<<ret<<endl;
}