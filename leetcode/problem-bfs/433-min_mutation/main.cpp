#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution{

public:
    int minMutation(string start, string end, vector<string>& bank){
        unordered_set<string> cnt;
        unordered_set<string> visited;
        char keys[4] = {'A', 'C', 'G', 'T'};
        for (auto & w: bank){
            cnt.emplace(w);
        }
        if(start==end) {
            return 0;
        }
        if (!cnt.count(end)) {
            return -1;
        }

        queue<string> q;
        q.emplace(start);
        visited.emplace(start);
        int step = 1;
        while (!q.empty()){
            int sz = q.size();
            for (int i=0;i<sz;i++){
                string cur = q.front();
                q.pop();
                for (int j=0;j<8;j++){
                    for (int k=0;k<4;k++){
                        if (keys[k] != cur[j]){
                            string next = cur;
                            next[j] = keys[k];
                            if (!visited.count(next) && cnt.count(next)){
                                if (next==end){
                                    return step;
                                }
                                q.emplace(next);
                                visited.emplace(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
    return -1;
    }
};



int main(){
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    int ret;
    Solution sol;
    ret = sol.minMutation(start, end, bank);
    cout<<ret<<endl;
}
