#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {

    }
    
    int ping(int t) {
        q.push(t);
        while (q.front()<t-3000){
            q.pop();
        }
        cout<<q.size()<<endl;
        return q.size();
    }
};

int main(){
    RecentCounter rc;
    rc.ping(100);
    rc.ping(3001);
    rc.ping(3100);
    rc.ping(3101);
}