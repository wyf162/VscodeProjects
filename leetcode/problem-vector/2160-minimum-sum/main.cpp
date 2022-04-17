#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        while (num){
            nums.emplace_back(num % 10);
            num /= 10 ;
        }
        sort(nums.begin(), nums.end());
        int ret = 0;
        ret = nums[0]*10+nums[1]*10+nums[2]+nums[3];
        return ret;
    }
    
};