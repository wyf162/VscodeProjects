#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int m, n;
    cin>>m>>n;
    cout<<m<<" "<<n<<endl;
    vector<vector<int>> a;

    for(int i=0;i<m;i++){
        vector<int> b;
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            b.push_back(t);
        }
        a.push_back(b);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}