#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();
        vector<int> left_product(n,1);
        vector<int> right_product(n,1);
        vector<int> result_product(n,1);
        for(int i=1;i<n;i++){
            left_product[i] = left_product[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right_product[i]=right_product[i+1]*nums[i+1];
        }
        for(int i=0; i<n; i++){
            result_product[i] = left_product[i]*right_product[i];
        }
        return result_product;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    vector<int> rets = sol.productExceptSelf(nums);
    for(auto ret:rets){
        cout<<ret<<" ";
    }
    return 0;
}