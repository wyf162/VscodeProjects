#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps)
    {
        vector<int> min_sec(18, INT32_MAX / 2);
        for (auto &tire : tires)
        {
            long time = tire[0];
            for (int x = 1, sum = 0; time <= changeTime + tire[0]; ++x)
            {
                sum += time;
                min_sec[x] = min(min_sec[x], sum);
                time *= tire[1];
            }
        }

        vector<int> dp(numLaps + 1, INT32_MAX);
        dp[0] = -changeTime;
        for (int i = 1; i <= numLaps; i++)
        {
            for (int j = 1; j <= min(17, i); ++j)
            {
                dp[i] = min(dp[i], dp[i - j] + min_sec[j]);
            }
            dp[i] += changeTime;
        }
        return dp[numLaps];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> tires{
        {1, 10}, {2, 2}, {3, 4}};
    int change_time = 5;
    int num_laps = 4;
    int ret = sol.minimumFinishTime(tires, change_time, num_laps);
    cout << ret << endl;
}