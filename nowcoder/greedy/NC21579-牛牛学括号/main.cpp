#include <cstdio>
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cstring>

using namespace std;
const int mod = 1e9+7;

int main(){
    char s[2505];
    int sum=1;
    ifstream fin("input.txt");
    fin >> s;
    stack<char> stk;
    stk.push(s[0]);
    for (int i=1;i<strlen(s);i++){
        if(s[i]=='('){
            stk.push(s[i]);
        }else{
            sum = (sum * stk.size()) % mod;
            stk.pop();
        }
    }
    cout << sum <<endl;
    return 0;
}