#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Trade {
public:
    int timestamp;
    string symbol;
    int quantity;
    int price;

    Trade(string record);
    void show(void);
};

Trade::Trade(string record) {
    istringstream s(record);
    string tmp;
    getline(s, tmp, ',');
    timestamp = stoi(tmp);
    getline(s, tmp, ',');
    symbol = tmp;
    getline(s, tmp, ',');
    quantity = stoi(tmp);
    getline(s, tmp, ',');
    price = stoi(tmp);
};

void Trade::show(void) {
    cout << "timestamp: " << timestamp << ", symbol: " << symbol << ", quantity: " << quantity << ", price: " << price << endl;
};

class TradeIndicator {
public:
    int last_timestamp;
    int max_gap;
    int total_quantity;
    int total_sum;
    int average_price;
    int max_price;

    TradeIndicator()=default;

    TradeIndicator(int last_timestamp, int max_gap, int total_qunatity, int total_sum, int average_price, int max_price) {
        last_timestamp = last_timestamp;
        max_gap = max_gap;
        total_quantity = total_quantity;
        total_sum = total_sum;
        average_price = average_price;
        max_price = max_price;
    };
};

class TradeAggregations {
public:
    unordered_map<string, TradeIndicator> hst;

    void update(Trade trade) {
        if (hst.find(trade.symbol) == hst.end()) {
            TradeIndicator trade_indacator(trade.timestamp, 0, trade.quantity,
                                               trade.price*trade.quantity, trade.price, trade.price);
            hst[trade.symbol] = trade_indacator;
        } else {
            hst[trade.symbol].max_gap = max(hst[trade.symbol].max_gap,
                                            trade.timestamp - hst[trade.symbol].last_timestamp);
            hst[trade.symbol].last_timestamp = trade.timestamp;
            hst[trade.symbol].total_quantity += trade.quantity;
            hst[trade.symbol].total_sum += trade.quantity * trade.price;
            hst[trade.symbol].average_price = hst[trade.symbol].total_sum / hst[trade.symbol].total_quantity;
            hst[trade.symbol].max_price = max(trade.price, hst[trade.symbol].max_price);
        }
    };

    void show() {
        for (auto kv : hst) {
            cout << kv.first << ", ";
            cout << kv.second.max_gap << ", ";
            cout << kv.second.total_quantity << ", ";
            cout << kv.second.average_price << ", ";
            cout << kv.second.max_price << ", " << endl;
        };
    }
};

int main() {
    unordered_map<string, Trade> records;
    string line;
    ifstream fin("input.csv");
    ofstream fout("output.csv");
    TradeAggregations trade_aggregations;
    while (getline(fin, line)) {
        Trade trade(line);
        trade.show();
        trade_aggregations.update(trade);
    };
    trade_aggregations.show();
    return 0;
};

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