#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a==b?-1:max(a.size(),b.size());
    }
};