#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int mult = 1;
        int n = s.size();
        int pos = -1;
        int h = 0;
        for (int i=n-1;i>=n-k;i--){
            h = ((long long)h*power+(s[i]-'a'+1))%modulo;
            if (i!=n-k){
                mult = (long long)mult*power%modulo;
            }
        }
        if (h==hashValue){
            pos = n-k;
        }
        for (int i=n-k-1;i>=0;i--){
            h = ((h-(long long)(s[i+k]-'a'+1)*mult%modulo+modulo)*power+(s[i]-'a'+1))%modulo;
            if (h==hashValue){
                pos = i;
            }
        }
        return s.substr(pos,k);
    }
};


int main(){
    Solution sol;
    string s="leetcode";
    int power=7;
    int modulo=20;
    int k=2;
    int hash_value=0;
    string ret = sol.subStrHash(s, power, modulo, k, hash_value);
    cout<<ret<<endl;
}