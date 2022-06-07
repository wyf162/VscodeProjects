#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    int numDistinct(string s, string t){
        int m = s.length(), n = t.length();
        if (m<n){
            return 0;
        }
        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1));
        for (int i=0; i<=m; i++){
            dp[i][n] = 1;
        }
        for (int i = m-1; i>=0;i--){
            char tChar = s.at(i);
            for (int j=n-1; j>=0;j--){
                char sChar = t.at(j);
                if (sChar == tChar) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                } else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    };

    string _s;
    string _t;


    int dfs(int i, int j, vector<vector<int>> &memo){
        if (j<0){
            return 1;
        }
        if (i<0){
            return 0;
        }

        if (memo[i][j] != -1){
            return memo[i][j];
        }

        int res = 0;
        if (_s[i] == _t[j]){
            res += dfs(i-1, j-1, memo);
            res += dfs(i-1, j, memo);
        }else{
            res += dfs(i-1, j, memo);
        }
        memo[i][j] = res;
        return res;
    }


    int numDistinct2(string s, string t){
        _s = s;
        _t = t;
        int n = s.length();
        int m = t.size();
        vector<vector<int>> memo(n , vector<int>(m, -1));
        return dfs(n-1, m-1, memo);
    }

};



int main(){
    string s = "rabbbit";
    string t = "rabbit";
    int ret;
    Solution sol;
    ret = sol.numDistinct2(s, t);
    cout<<ret<<endl;
}