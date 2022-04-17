#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        vector<int> pre;
        pre.emplace_back(0);
        for(auto num:nums){
            pre.emplace_back(pre.back()+num);
        }
        if(pre.back()<target){
            return 0;
        }
        int l=0,r=nums.size();
        while(l<r){
            int m = (l+r)/2;
            if(check(pre,target,m)){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }

    bool check(vector<int>& nums, int target, int k){
        int n=nums.size();
        int i=k;
        bool tag=false;
        while(i<n){
            if(nums[i]-nums[i-k]>=target){
                tag=true;
                break;
            }
            i++;
        }
        return tag;
    }
};


int main(){
    Solution sol;
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    int ret = sol.minSubArrayLen(target, nums);
    cout<<ret<<endl;
}