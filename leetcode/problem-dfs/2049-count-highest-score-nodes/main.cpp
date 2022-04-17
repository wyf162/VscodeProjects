#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    long maxScore = 0;
    int cnt=0;
    int n ;
    vector<vector<int>> children;

    int dfs(int node){
        long score = 1;
        int size = n-1;
        for(int c: children[node]){
            int t = dfs(c);
            score *= t;
            size -= t;
        }
        if (node!=0){
            score *= size;
        }
        if (score==maxScore){
            cnt++;
        }else if (score>maxScore){
            maxScore=score;
            cnt = 1;
        }
        return n-size;
    }

    int countHighestScoreNodes(vector<int>& parent){
        this->n = parent.size();
        this->children=vector<vector<int>>(n);
        for(int i=0;i<n;i++){
            int p = parent[i];
            if (p!=-1){
                children[p].emplace_back(i);
            }
        }
        dfs(0);
        return cnt;
    }
};


int main(){
    Solution sol;
    vector<int> parents = {-1,2,0,2,0};
    int cnt = sol.countHighestScoreNodes(parents);
    cout<<cnt<<endl;
}