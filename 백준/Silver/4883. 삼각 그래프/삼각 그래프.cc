#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define first Y
#define second X
#define endl "\n"
using namespace std;
typedef long long ll;


int main() {
    FAST_IO;
    int test_case = 0;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        int graph[100001][3] = {0,};
        ++test_case;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> graph[i][j];
            }
        }
        int dp[100001][3] = {0,};

        dp[1][0] = 987654321;
        dp[1][1] = graph[1][1];
        dp[1][2] = graph[1][2] + graph[1][1];

        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
            dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][1], min(dp[i][0], dp[i - 1][2]))) + graph[i][1];
            dp[i][2] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i][1])) + graph[i][2];
        }

        cout << test_case << ". " << dp[n][1] << endl;
    }

    return 0;
}

