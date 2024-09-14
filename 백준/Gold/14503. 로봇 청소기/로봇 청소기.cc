#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second

#define MAX 51
using namespace std;
typedef long long ll;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

struct Machine {
	int y;
	int x;
	int dir;
};
int board[MAX][MAX];
int n, m;

int rotate_dir_counterclockwise(int dir) {
	// 0 -> 3 , 1 -> 0, 2 -> 1, 3 -> 2
	return (dir + 3) % 4;
}

int main() {
	FAST_IO;
	
    cin >> n >> m;

    Machine ma = { 0, 0, 0 };
    cin >> ma.y >> ma.x >> ma.dir;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    bool is_stopped = false;

    while (!is_stopped) {
        // 1. 현재 칸이 아직 청소되지 않은 경우 청소
        if (board[ma.y][ma.x] == 0) {
            board[ma.y][ma.x] = -1;
            ans++;
        }

        bool clean_4_way_possible = false;

        // 2. 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인
        for (int w = 0; w < 4; w++) {
            int ny = ma.y + dy[w];
            int nx = ma.x + dx[w];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;  // 범위 초과
            if (board[ny][nx] == 0) {  // 청소되지 않은 빈 칸이 있음
                clean_4_way_possible = true;
                break;
            }
        }

        if (clean_4_way_possible) {
            // 반시계 방향으로 회전
            ma.dir = rotate_dir_counterclockwise(ma.dir);
            int ny = ma.y + dy[ma.dir];
            int nx = ma.x + dx[ma.dir];

            // 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진
            if (ny >= 0 && nx >= 0 && ny < n && nx < m && board[ny][nx] == 0) {
                ma.y = ny;
                ma.x = nx;
            }
            continue;  // 조건을 만족한 경우 계속해서 청소 진행
        }

        // 3. 주변 4칸 모두 청소되었거나 벽인 경우
        int back_y = ma.y - dy[ma.dir];
        int back_x = ma.x - dx[ma.dir];

        // 뒤쪽이 벽이 아니면 후진
        if (back_y >= 0 && back_x >= 0 && back_y < n && back_x < m && board[back_y][back_x] != 1) {
            ma.y = back_y;
            ma.x = back_x;
        }
        else {
            // 뒤쪽이 벽이라 후진할 수 없으면 작동 종료
            is_stopped = true;
        }
    }

    cout << ans << endl;
    return 0;
}