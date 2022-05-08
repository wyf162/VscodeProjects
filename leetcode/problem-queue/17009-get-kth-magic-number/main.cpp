#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        set<long> q;
        long ans;
        q.insert(1);
        while (k--) {
            ans = * q.begin();
            q.erase(q.begin());
            q.insert(ans * 3);
            q.insert(ans * 5);
            q.insert(ans * 7);
        }
        return ans;
    }

    int getKthMagicNumber2(int k){
        vector<int> store = {3,5,7};
        priority_queue<long, vector<long>, greater<long>> pqm;
        unordered_set<long> ust;
        ust.insert(1);
        pqm.push(1);
        long temp;
        for(int i=0; i<k; i++){
            temp = pqm.top();
            pqm.pop();
            for(auto &num:store){
                if(ust.find(num*temp)==ust.end()){
                    pqm.push(num*temp);
                    ust.insert(num*temp);
                }
            }
        }
        return temp;
    }

};

int
main() {
    Solution sol;
    int ret;
    ret = sol.getKthMagicNumber(5);
    cout<<ret<<endl;
}