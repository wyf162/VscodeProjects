#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int longestValidParentheses(string s){
        if (s==""){
            return 0;
        }
        int n = s.size();
        vector<int> dp(n,0);
        for (int i=1; i<n; i++){
            if(s[i]==')' && s[i-1]=='('){
                if (i-2>0){
                    dp[i] = dp[i-2]+2;
                    if(i-dp[i-2]-2>0){
                        dp[i] += dp[i-dp[i-2]-2];
                    }
                } else{
                    dp[i] = 2;
                }
            }else if (s[i]==')'){
                if (i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                    dp[i] = dp[i-1]+2;
                    if(i-dp[i-1]-2>0){
                        dp[i] += dp[i-dp[i-1]-2];
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main(){
    // string s= ")(()())";
    // string s= "()(())";
    string s = "(()())";
    // string s = ")()())";
    int ret;
    Solution sol;
    ret = sol.longestValidParentheses(s);
    cout<<ret<<endl;
}