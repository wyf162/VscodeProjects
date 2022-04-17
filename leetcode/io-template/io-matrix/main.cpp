#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;

int main(){
    ifstream fin("input.txt");
    fstream fout("output.txt", fstream::out);
    int a,b;
    fin>>a>>b;
    fout<<a<<b;
    vector<vector<int> > mtx;
    string tmp;
    for(int i=0;i<b;i++){
        getline(fin, tmp);
        istringstream out(tmp);
        string num;
        while(getline(out, num)){
            cout<<num;
            // mtx[i].push_back(stoi(num));
        };
    }
    // for(int i=0;i<a;i++){
    //     for(int j=0;j<b;j++){
    //         fout<<mtx[i][j]<<",";
    //     }
    //     fout<<"\n";
    // }
    return 0;
}