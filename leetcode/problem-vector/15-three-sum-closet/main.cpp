#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;
        auto update = [&](int cur){
            if(abs(cur-target)<abs(best-target)){
                best = cur;
            }
        };

        for (int i=0;i<n;i++){
            if (i>0 && nums[i] == nums[i-1]){
                continue;
            }

            int j=i+1,k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                update(sum);
                if(sum>target){
                    k -= 1;
                }else{
                    j += 1;
                }
            }
        }
        return best;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {-1,2,-1,4};
    int target=1;
    int ret = sol.threeSumClosest(nums,target);
    cout<<ret<<endl;
}