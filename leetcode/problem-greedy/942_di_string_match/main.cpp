#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> diStringMatch(string s){
        int n = s.size();
        int lo = 0, hi = n;
        vector<int> perm(n+1);
        for (int i=0; i<n; i++){
            perm[i] = s[i]=='I' ? lo++ : hi--;
        }
        perm[n] = lo;
        return perm;
    }
};

int main(){
    string s="IDID";
    Solution sol;
    vector<int> rets;
    rets = sol.diStringMatch(s);
    for (auto ret: rets){
        cout<<ret<<endl;
    }
}