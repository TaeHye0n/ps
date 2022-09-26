#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    string tmp = "";
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] != '{' && s[i] != ',' && s[i] != '}'){
            tmp += s[i];
        
        if(s[i+1] == '}' || s[i+1] == ','){
            m[stoi(tmp)]++;
            tmp = "";
        }
        }
    }
  
    
    vector<pair<int,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for(auto pp : v){
        answer.push_back(pp.first);
    }
    return answer;
}