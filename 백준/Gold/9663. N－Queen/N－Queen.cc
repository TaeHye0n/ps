#include <iostream>
#include <vector>

using namespace std;


const int dy[8] = { 1,-1,0,0,1,1,-1,-1 };
const int dx[8] = { 0,0,1,-1,1,-1,-1,1 };
int board[16][16];
int visited[16][16];
int n;
int answer;

void dfs(int num) {
    if (num == n) {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++) {
        int y = num;
        int x = i;
        bool flag = false;
        if (visited[y][x] != 0) continue;
        vector<pair<int, int>> temp;
        visited[y][x] = num + 1;
        temp.push_back({ y,x });
        for (int w = 0; w < 8; w++) {
            int ny = y;
            int nx = x;
            while (1) {
                ny += dy[w];
                nx += dx[w];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;

                if (visited[ny][nx] == 0) {
                    visited[ny][nx] = num + 1;
                    temp.push_back({ ny,nx });
                }
            }
        }
        dfs(num + 1);
        for (int i = 0; i < temp.size(); i++) {
            visited[temp[i].first][temp[i].second] = 0;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    cin >> n;
    dfs(0);
    cout << answer;
}