#include<iostream>
#include<memory>

using namespace std;

int main(){
    auto p = make_shared<int>(9);
    cout<<*p<<endl;
    auto q(p);
    *q=99;
    cout<<*q<<endl;
    cout<<p<<" "<<q<<endl;
}