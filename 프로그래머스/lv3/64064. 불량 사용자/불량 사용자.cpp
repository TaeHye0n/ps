#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

set<string> s;
vector<string> userId, bannedId;
bool visited[9];

void dfs(int idx){
    if(idx == bannedId.size()){
        string str = "";
        for(int i = 0; i < userId.size(); i++){
            if(visited[i]) str += userId[i];
        }
        s.insert(str);
        return;
    }
    
    for(int i = 0; i < userId.size(); i++){
        if(visited[i]) continue;
        if(userId[i].length() != bannedId[idx].length()) continue;
        
        bool find = true;
        for(int j = 0; j < bannedId[idx].length(); j++){
            if(bannedId[idx][j] == '*') continue;
            else if(bannedId[idx][j] != userId[i][j]){
                find = false;
                break;
            }
        }
        if(find){
            visited[i] = true;
            dfs(idx+1);
            visited[i] = false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    userId = user_id;
    bannedId = banned_id;
    
    dfs(0);
    return s.size();
}