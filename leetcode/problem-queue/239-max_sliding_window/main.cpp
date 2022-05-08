#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; i++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }

    vector<int> maxSlidingWindow2(vector<int> &nums, int k){
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i<k; i++){
            while (!q.empty() && nums[i]>=nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans = {nums[q.front()]};
        for(int i=k; i<n; i++){
            while (!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i-k){
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> rets;
    Solution sol;
    rets = sol.maxSlidingWindow2(nums, 3);
    for (auto ret : rets) {
        cout << ret << endl;
    }
}