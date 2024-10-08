#include <string>
#include <vector>

using namespace std;

int N; // 자물쇠의 크기 <= 20
int M; // 열쇠의 크기 <= 20
int cnt; // 자물쇠 홈의 개수
bool answer;

// 열쇠는 회전과 이동이 가능하다. (90도 회전은 최대 4번한다. 4번 하기 때문에 반시계 구분 필요 없음)
// 자물쇠 영역내에서 열쇠의 돌기 부분과 자물쇠 홈 일치
// 자물쇠 영역내에서 열쇠의 돌기와 자물쇠의 돌기가 만나서는 안된다.
// 자물쇠와 열쇠의 크기가 다르다. 어떻게 비교해야 할까 -> 큰 격자에 자물쇠를 두고 그 위에서 key를 이동시켜본다
vector<vector<int>> rotate_clockwise(vector<vector<int>> key) {
    vector<vector<int>> v(M, vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            v[i][j] = key[M - j - 1][i];
        }
    }
    return v;
}

bool check(vector<vector<int>> key, vector<vector<int>> lock, int y_offset, int x_offset) {
    int cnt2 = 0; // 맞물리는 홈의 개수를 세기 위한 변수
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int y = i + y_offset;
            int x = j + x_offset;

            if (y < 0 || x < 0 || y >= N || x >= N) continue;

            if (lock[y][x] == 1 && key[i][j] == 1) return false;

            if (lock[y][x] == 0 && key[i][j] == 1) cnt2++;
        }
    }

    return cnt2 == cnt;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    N = lock.size();
    M = key.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lock[i][j] == 0) cnt++;
        }
    }
    
    for (int r = 0; r < 4; r++) {
        for (int i = 1 - M; i < N; i++) {
            for (int j = 1 - M; j < N; j++) {
                if (check(key, lock, i ,j)) {
                    return true;
                }
            }
        }
        key = rotate_clockwise(key);
    }
    
    return false;
}