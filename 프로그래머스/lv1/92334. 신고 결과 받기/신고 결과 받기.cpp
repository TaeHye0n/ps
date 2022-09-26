#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

map<string, int> reported;
map<string, set<string>> reporting;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(auto s : report){
        int space = s.find(' ');
        string from = s.substr(0, space);
        string to = s.substr(space);
        
        if(reporting[from].find(to) == reporting[from].end()){
            reported[to]++;
            reporting[from].insert(to);
        }
    }
    for(auto s : id_list){
        int cnt = 0;
        for(string s2: reporting[s]){
            if(reported[s2] >= k) cnt++;
        }
        answer.push_back(cnt);
        
    }
    
    return answer;
}