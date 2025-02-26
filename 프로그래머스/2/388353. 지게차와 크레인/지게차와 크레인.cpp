#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int dy[4] = {1, -1, 0 ,0};
int dx[4] = {0, 0, 1, -1};

void pick_lift(vector<string>& storage, char alpha) {
    vector<string> temp = storage;
    vector<vector<bool>> reachable(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && storage[i][j] == '0') {
                reachable[i][j] = true;
                q.push({i, j});
            }
        }
    }
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int w = 0; w < 4; w++) {
            int ny = y + dy[w], nx = x + dx[w];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (storage[ny][nx] == '0' && !reachable[ny][nx]) {
                reachable[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] == alpha) {
                bool accessible = false;
                for (int w = 0; w < 4; w++) {
                    int ny = i + dy[w], nx = j + dx[w];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                        accessible = true;
                        break;
                    }
                    if (storage[ny][nx] == '0' && reachable[ny][nx]) {
                        accessible = true;
                        break;
                    }
                }
                if (accessible) {
                    temp[i][j] = '0';
                }
            }
        }
    }
    storage = temp;
}

void pick_crane(vector<string>& storage, char alpha) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] == alpha) {
                storage[i][j] = '0';
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].size();
    
    for (int i = 0; i < requests.size(); i++) {
        string req = requests[i];
        if (req.size() == 1) {
            pick_lift(storage, req[0]);
        } else {
            pick_crane(storage, req[0]);
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] != '0') answer++;
        }
    }
    return answer;
}