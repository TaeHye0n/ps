#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> m;
    
    for(int i = 0; i < players.size(); i++){
        m[players[i]] = i;
    }
    
    for(string s : callings){
        int cur = m[s];
        int front = cur - 1;
        m[s] = front;
        m[players[front]] = cur;
        string temp = players[cur];
        players[cur] = players[front];
        players[front] = temp;
    }
    
    return players;
}