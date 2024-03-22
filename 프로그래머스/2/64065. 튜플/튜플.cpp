#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int ,int> p1, pair<int ,int> p2) {
    return p1.second > p2.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;

    string temp = "";
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            temp += c;
        } else {
            if (temp.size() == 0) continue;
            m[stoi(temp)]++;
            temp.clear();
        }
    }
    
    vector<pair<int,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for (auto val : v) {
        answer.push_back(val.first);
    }
    return answer;
}