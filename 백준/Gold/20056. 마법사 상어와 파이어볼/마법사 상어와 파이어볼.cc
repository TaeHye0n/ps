#include <iostream>
#include <vector>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 51

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1 ,-1};

int N, M, K;

struct fireBall {
    int r;
    int c;
    int m;
    int s;
    int d;
};

vector<fireBall> fireBalls;
vector<fireBall> board[MAX][MAX];

bool isAllSameDir(int y, int x);

void move() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            board[i][j].clear();
        }
    }
    
    for (int i = 0; i < fireBalls.size(); i++) {
        fireBall &cur = fireBalls[i];
        int cy = cur.r;
        int cx = cur.c;
        int speed = cur.s % N;
        
        int ny = cy + speed * dy[cur.d];
        int nx = cx + speed * dx[cur.d];
        
        if (ny > N) ny -= N;
        if (nx > N) nx -= N;
        if (nx < 1) nx += N;
        if (ny < 1) ny += N;
        cur.r = ny;
        cur.c = nx;
        board[ny][nx].push_back({ny, nx, cur.m, cur.s, cur.d});
    }
}

void sumAndSplit() {
    vector<fireBall> temp;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j].size() == 0) continue;
            if (board[i][j].size() == 1) temp.push_back(board[i][j][0]);
            else {
                int massSum = 0, speedSum = 0;
                int size = board[i][j].size();
                for (int k = 0; k < size; k++) {
                    massSum += board[i][j][k].m;
                    speedSum += board[i][j][k].s;
                }
                int mass = massSum / 5;
                if (mass == 0) continue;
                int speed = speedSum / size;
                int start = 0;
                if (!isAllSameDir(i, j)) start = 1;
                for (int k = 0; k <= 7; k += 2) {
                    temp.push_back({i, j, mass, speed, start + k});
                }
            }
        }
    }
    fireBalls = temp;
}

bool isAllSameDir(int y, int x) {
    bool isOdd = true;
    bool isEven = true;
    
    for (int i = 0; i < board[y][x].size(); i++) {
        fireBall cur = board[y][x][i];
        if (cur.d % 2 == 0) isOdd = false;
        else isEven = false;
    }
    
    if (isOdd || isEven) return true;
    return false;
}



int main() {
    FAST_IO;
    
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        fireBalls.push_back({a, b, c, d, e});
    }
    
    for (int t = 0; t < K; t++) {
        // 1. 이동
        move();
        // 2. 합쳐지고 나누어짐
        sumAndSplit();
    }
    int answer = 0;
    
    for (int i = 0; i < fireBalls.size(); i++) {
        answer += fireBalls[i].m;
    }
    cout << answer;
}
