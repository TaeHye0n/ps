#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int timeCal(string a, string b){
    int time = 0;
    time = 60*(stoi(b.substr(0,2))- stoi(a.substr(0,2))) + (stoi(b.substr(2,2)) - stoi(a.substr(2,2)));
    return time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> m;
    
    for(int i = 0; i < records.size(); i++){
         string num ="";
         string time ="";
         time = records[i].substr(0,2)+records[i].substr(3,2);
         num = records[i].substr(6,4);
         m[num].push_back(time);
        }
    for(auto& number : m){
        int fee = 0;
        if(number.second.size() % 2 != 0) number.second.push_back("2359");
        int time = 0;
        for(int i = 0; i < number.second.size()-1; i+=2){
            time += timeCal(number.second[i], number.second[i+1]);
        }
        int price = fees[1];
        if(time > fees[0]){
            price += ceil((double)(time-fees[0])/fees[2])*fees[3];
        }
        
        answer.push_back(price);
    }
    
    return answer;
}