#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> hst{
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},
            {90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"},
        };
        vector<int> keys={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int idx=0;
        string ans;
        while(idx<keys.size()){
            if(num>=keys[idx]){
                ans += hst.at(keys[idx]);
                num -= keys[idx];
            }else{
                idx += 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int num = 1994;
    string ret = sol.intToRoman(num);
    cout<<ret<<endl;
}