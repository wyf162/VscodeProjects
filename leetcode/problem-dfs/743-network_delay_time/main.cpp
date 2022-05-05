#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT32_MAX / 2;
        vector<vector<pair<int, int>>> g(n);
        for (auto &t : times){
            int x = t[0]-1;
            int y = t[1]-1;
            g[x].emplace_back(y,t[2]);
        }

        vector<int> dist(n, inf);
        dist[k-1]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k-1);
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first;
            int x = p.second;
            if (dist[x]<time){
                continue;
            }
            for (auto &e : g[x]){
                int y = e.first;
                int d = dist[x]+e.second;
                if (d<dist[y]){
                    dist[y]=d;
                    q.emplace(d,y);
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};


int main(){
    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };
    int ret;
    Solution sol;
    ret = sol.networkDelayTime(times,4,2);
    cout<<ret<<endl;
}