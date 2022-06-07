#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int ret = 0;
        bool tag = true;
        for (int i=0;i<n;i++){
            tag = true;
            for (int j=1;j<m;j++){
                cout<<strs[j-1][i]<<" "<<strs[j][i]<<endl;
                if (strs[j-1][i]>strs[j][i]){
                    tag = false;
                    break;
                }
            }
            if (tag==false){
                cout<<i<<endl;
                ret += 1;
            }
        }
        return ret;
    }
};



int main(){
    vector<string> strs = {"cba","bce","cae"};
    int ret = 0;
    Solution sol;
    ret = sol.minDeletionSize(strs);
    cout<<ret<<endl;
}