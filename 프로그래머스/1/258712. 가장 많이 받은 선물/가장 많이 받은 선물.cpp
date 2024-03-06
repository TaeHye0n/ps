#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
#define endl "\n"

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, map<string, int>> gat;
    map<string, int> degree;
    map<string, map<string, bool>> visited;
    
    for (string s : friends) {
        for (string s2 : friends) {
            if (s == s2) continue;
            gat[s][s2] = 0;
            visited[s][s2] = false;
            visited[s2][s] = false;
        }
    }
    for(string s : gifts) {
        int idx = s.find(" ");
        string from = s.substr(0, idx);
        string to = s.substr(idx+1);
        gat[from][to]++;
        degree[from]++;
        degree[to]--;
    }
    
    
    map<string, int> newdegree;
    for (string s : friends) {
        for (auto m : gat[s]) {
            string to = m.first;
            int amount = m.second;
            if (visited[s][to] || visited[to][s]) continue;
            if (amount != 0 || gat[to][s] != 0) {
                if (amount > gat[to][s]) {
                    newdegree[s]++;
                } else if (amount < gat[to][s]) {
                    newdegree[to]++;
                } else {
                    if (degree[s] > degree[to]) {
                        newdegree[s]++;
                    } else if (degree[s] < degree[to]) {
                        newdegree[to]++;
                    }
                }
            } else {
                 if (degree[s] > degree[to]) {
                        newdegree[s]++;
                    } else if (degree[s] < degree[to]) {
                        newdegree[to]++;
                    }
            }
                visited[s][to] = true;
                visited[to][s] = true;
        }
    }    
    
    for (auto itr = newdegree.begin(); itr != newdegree.end(); itr++) {
        answer = max(answer, itr->second);
    }
    
    return answer;
}