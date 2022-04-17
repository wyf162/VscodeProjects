#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


struct Trade{
    int last_timestamp;
    int max_gap;
    int total_quantity;
    int total_price;
    int average_price;
    int max_price;
};

int main(){
    
    unordered_map<string, Trade> records;
    sring line;
    ifstream fin("input.csv");
    ofstream fout("output.csv");
    while(getline(fin, line)){
        
    }


}


// int main() {
//     int timestamp;
//     string symbol;
//     int quantity;
//     int price;
//     unordered_map<string, pair<int, int>> max_gap;
//     unordered_map<string, int> total_volume;
//     unordered_map<string, double> average_price;

//     string line;
//     cout << "start to read line from file" << endl;
//     ifstream fp("input.csv");
//     ofstream fout("output.csv");
//     while (getline(fp, line)) {
//         cout << line << endl;
//         string tmp;
//         istringstream record(line); // string 数据流化
//         getline(record, tmp, ',');
//         timestamp = stoi(tmp);
//         getline(record, tmp, ',');
//         symbol = tmp;
//         getline(record, tmp, ',');
//         quantity = stoi(tmp);
//         getline(record, tmp, ',');
//         price = stoi(tmp);
//         cout << timestamp << " " << symbol << " " << quantity << " " << price << endl;
//         if(max_gap.find(symbol)==max_gap.end()){
//             max_gap[symbol] = make_pair(timestamp, 0);
//             total_volume[symbol] = quantity;
//             average_price[symbol] = price;
//         }else{
//             if(timestamp-max_gap[symbol].first>max_gap[symbol].second){
//                 max_gap[symbol].second = timestamp-max_gap[symbol].first;
//             };
//             max_gap[symbol].first=timestamp;
            
//             double avg;
//             avg = total_volume[symbol]*average_price[symbol]+quantity*price;
//             total_volume[symbol] += quantity;
//             avg = avg / total_volume[symbol];
//             average_price[symbol] = avg;
//         }  
//     }
//     for(auto kv: max_gap){
//         symbol = kv.first;
//         fout<<kv.first<<","<<kv.second.second<<","<<total_volume[symbol]<<","<<average_price[symbol]<<endl;
//     }
// }