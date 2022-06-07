#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.length();
        int n = second.length();
        if (m==n){
            int k = 0;
            for (int i=0;i<m;i++){
                if (first[i]!=second[i]){
                    k++;
                }
            }
            return k<=1?true:false;
        }else if(m+1==n){
            int k=0;
            int offset=0;
            for (int i=0;i<m;i++){
                if (first[i]!=second[i+offset]){
                    k++;
                    offset=1;
                    if (first[i]!=second[i+offset]){
                        k++;
                    }
                }
            }
            return k<=1?true:false;
        }else if (n+1==m){
            int k=0;
            int offset=0;
            for (int i=0;i<n;i++){
                if (first[i+offset]!=second[i]){
                    k++;
                    offset=1;
                    if (first[i+offset]!=second[i]){
                        k++;
                    }
                }
            }
            return k<=1?true:false;
        }else{
            return false;
        }

    }
};




int main(){
    string first = "teacher";
    string second = "bleacher";
    Solution sol;
    bool ret;
    ret = sol.oneEditAway(first, second);
    cout<<ret<<endl;
}