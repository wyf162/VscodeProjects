#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n,0);
    int ans=0;
    int idx=0;
    for(int i=1; i<n; i++){
        if(s[i]=='(' || s[i]=='['){
            continue;
        }else if((s[i]==')' && s[i-dp[i-1]-1]=='(') || (s[i]==']' && s[i-dp[i-1]-1]=='[')){
            if(i-dp[i-1]-2>=0){
                dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
            }else{
                dp[i]=dp[i-1]+2;
            }
            if(dp[i]>ans){
                ans=dp[i];
                idx=i;
            }
        }
    }
    // cout<<idx<<" "<<ans<<endl;
    cout<<s.substr(idx-ans+1, ans)<<endl;
    return 0;
}