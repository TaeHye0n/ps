#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

int time_to_sec(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3 , 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> num_and_fee;
    
    map<string, vector<int>> stamp;
    
    for (auto record : records) {
        stringstream ss;
        ss.str(record);
        string time_stamp, car_number;
        ss >> time_stamp >> car_number;
        // cout << time_stamp << " " << car_number << "\n";
        stamp[car_number].push_back(time_to_sec(time_stamp));
    }
    
    for (auto itr = stamp.begin(); itr != stamp.end(); itr++) {
        string car_number = itr->first;
        int amount = 0; // 누적 주차 시간
        vector<int> record = itr->second;
        if (record.size() % 2 == 1) {
            record.push_back(time_to_sec("23:59"));
        }
        
        for (int i = 0; i < record.size() - 1; i += 2) {
            amount += (record[i + 1] - record[i]);
        }
        int fee = fees[1];
        
        if (amount > fees[0]) {
           fee += ceil((double) (amount - fees[0]) / fees[2]) * fees[3];    
            
        } 
        
        num_and_fee.push_back({car_number, fee});
    }
    
    sort(num_and_fee.begin(), num_and_fee.end());
    
    for (int i = 0; i < num_and_fee.size(); i++) {
        answer.push_back(num_and_fee[i].second);
    }
    return answer;
}