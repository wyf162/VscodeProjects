#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {

public:
    int countQuardruplets(vector<int>& nums){
        int cnt=0;
        unordered_map<int, int> hst;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                for (int k=j+1;k<n;k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    for(int l=k+1;l<n;l++){
                        if(nums[l]==sum){
                            cnt += 1;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};


int main(){
    vector<int> nums = {28,8,49,85,37,90,20,8};
    Solution sol;
    int ret;
    ret = sol.countQuardruplets(nums);
    cout<<ret<<endl;
}