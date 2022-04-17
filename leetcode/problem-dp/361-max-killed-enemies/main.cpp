#include<iostream>
#include<vector>
using namespace std;


class Solution {
    int dir_x[4]={0,1,0,-1};
    int dir_y[4]={1,0,-1,0};
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if((int) grid.size()==0) return 0;
        int ans=0,n=(int)grid.size(),m=(int)grid[0].size();
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++)if(grid[i][j]=='0'){
                int cnt=0;
                for (int k=0;k<4;k++){
                    int tx=i,ty=j;
                    while (tx>=0 && tx<n && ty>=0 && ty<m && grid[tx][ty]!='W'){
                        cnt +=grid[tx][ty]=='E';
                        tx+=dir_x[k];
                        ty+=dir_y[k];
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    };
public:
    int maxKilledEnemies2(vector<vector<char>>& grid) {
        if ((int)grid.size()==0) return 0;
        int ans=0,pre,n=(int)grid.size(),m=(int)grid[0].size();
        vector<vector<int>> boom(n,vector<int> (m,0));
        for (int i=0;i<n;++i){
            pre=0;
            for (int j=0;j<m;++j){// 从左往右
                if (grid[i][j]=='W') pre=0;
                else if (grid[i][j]=='E') pre+=1;
                boom[i][j]+=pre;
            }

            pre=0;
            for (int j=m-1;j>=0;--j){// 从右往左
                if (grid[i][j]=='W') pre=0;
                else if (grid[i][j]=='E') pre+=1;
                boom[i][j]+=pre;
            }
        }
        for (int j=0;j<m;++j){
            pre=0;
            for (int i=0;i<n;++i){// 从上到下
                if (grid[i][j]=='W') pre=0;
                else if (grid[i][j]=='E') pre+=1;
                boom[i][j]+=pre;
            }

            pre=0;
            for (int i=n-1;i>=0;--i){// 从下到上
                if (grid[i][j]=='W') pre=0;
                else if (grid[i][j]=='E') pre+=1;
                boom[i][j]+=pre;
            }
        }
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j)if(grid[i][j]=='0'){
                ans=max(ans,boom[i][j]);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid {
        {'0','E','0','0'},
        {'E','0','W','E'},
        {'0','E','0','0'},
    };
    int ret = sol.maxKilledEnemies(grid);
    cout<<ret<<endl;

}