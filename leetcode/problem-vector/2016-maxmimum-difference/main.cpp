#include<iostream>
#include<stack>
#include<vector>

using namespace std;


class Solution{
public:
    int maximumDifference(vector<int>& nums){
        int ans = -1;
        int pre = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>pre){
                ans = max(ans,nums[i]-pre);
            }else{
                pre = nums[i];
            }
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {7,1,5,4};
    int ans = sol.maximumDifference(nums);
    cout<<ans<<endl;
}