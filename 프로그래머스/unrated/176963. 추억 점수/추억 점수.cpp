#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> m;
    
    for(int i = 0; i < name.size() ;i++){
        string who = name[i];
        int point = yearning[i];
        m.insert({who, point});
    }
    
    for(auto p : photo){
        int res = 0;
        for(string s : p){
            res += m[s];
        }
        answer.push_back(res);
    }
    return answer;
}