#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define first Y
#define second X
#define endl "\n"

#define MAX 17
using namespace std;
typedef long long ll;


int N; // 집의 크기 3 <= N <= 16
int board[MAX][MAX];
int dp[MAX][MAX][3];

int main() {
    FAST_IO;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    dp[1][2][0] = 1;

    for (int i = 3; i <= N; i++) {
        if (board[1][i] == 1) break;
        dp[1][i][0] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 3; j <= N; j++) {
            if (board[i][j] == 1) continue;

            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
            dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

            if (board[i - 1][j] == 1 || board[i][j - 1] == 1) continue;

            dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }

    int ans = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    cout << ans;
    return 0;
}

