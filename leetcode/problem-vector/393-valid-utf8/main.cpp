#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int n = data.size();
        int i = 0;
        bool ret = true;
        while (i < n) {
            if (data[i] < 128) {
                i = i + 1;
            } else if (data[i] >= 192 && data[i] < 224) {
                if (i + 1 >= n) {
                    return false;
                }
                ret = (data[i + 1] >= 128);
                i = i + 2;
            } else if (data[i] >= 224 && data[i] < 240) {
                if (i + 2 >= n) {
                    return false;
                }
                ret = (data[i + 1] >= 128 && data[i + 2] >= 128);
                i = i + 3;
            } else if (data[i] >= 240 && data[i] < 248) {
                if (i + 3 >= n) {
                    return false;
                }
                ret = (data[i + 1] >= 128 && data[i + 2] >= 128 && data[i + 3] >= 128);
                i = i + 4;
            } else {
                ret = false;
            }
            if (ret == false) {
                return ret;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> data = {197, 130, 1};
    bool ret = sol.validUtf8(data);
    cout << ret << endl;
}