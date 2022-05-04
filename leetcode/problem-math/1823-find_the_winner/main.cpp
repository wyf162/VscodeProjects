#include <iostream>
#include <queue>

using namespace std;



class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i=1;i<=n;i++){
            q.emplace(i);
        }
        while (q.size()>1){
            for (int i=1;i<k;i++){
                q.emplace(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};


int main(){
    Solution sol;
    int n=5,k=2;
    int ret;
    ret = sol.findTheWinner(n, k);
    cout<<ret<<endl;
}