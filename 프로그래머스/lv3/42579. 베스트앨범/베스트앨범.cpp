#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string,int>& a, pair<string,int>& b){
    return a.second > b.second;
}
bool cmp2(pair<int,pair<string,int>>& a, pair<int,pair<string,int>>& b){
    if(a.first == b.first) return a.second.second < b.second.second;
    else return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> playscnt;
    vector<pair<int,pair<string,int>>> v;
    
    for(int i = 0; i < genres.size(); i++){
        playscnt[genres[i]] += plays[i];
        v.push_back({plays[i], {genres[i],i}});
    }
    vector<pair<string, int>> vt(playscnt.begin(), playscnt.end());
    sort(vt.begin(), vt.end(), cmp);
    sort(v.begin(), v.end(), cmp2);
    
    for(int i = 0; i < vt.size(); i++){
        int cnt = 0;
        for(int j = 0; j < v.size(); j++){
            if(v[j].second.first == vt[i].first) {
                answer.push_back(v[j].second.second);
                cnt++;
            }
            if(cnt == 2) break;
        }
    }
    return answer;
}