#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>

using namespace std;

int main(){
    istringstream input("abc,def,gh");
    string word;
    while(getline(input, word, ',')){
        cout<<word<<endl;
    }
    istringstream input2("a,b,c,d,e,f,g");
    for(string line; getline(input2, line, ',');){
        cout<<line<<endl;
    }

}