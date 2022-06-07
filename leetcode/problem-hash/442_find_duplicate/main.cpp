#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDuplicate(vector<int>& nums){
        unordered_map<int, int> hst;
        for (auto &num: nums){
            hst[num]++;
        }
        vector<int> rets;
        // for (auto it: hst){
        //     if (it.second==2){
        //         rets.push_back(it.first);
        //     }
        // }
        for (auto& [k, v]: hst){
            if (v==2){
                // rets.push_back(k);
                // rets.emplace(rets.end(), k);
                rets.emplace_back(k);
            }
        }

        return rets;
    }

    vector<int> findDuplicate2(vector<int>& nums){
        int n = nums.size();
        for (int i=0;i<n;i++){
            while (nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        vector<int> ans;
        for (int i=0; i<n;i++){
            if (nums[i]-1!=i){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};


int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution sol;
    vector<int> rets;
    rets = sol.findDuplicate(nums);
    for (auto &ret: rets){
        cout<<ret<<endl;
    }
}