#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define MAX 1000001

int n;
int line[MAX];
int dp[MAX];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> line[i];
    }
}

int main() {
    FAST_IO;
    input();
    dp[0] = 0;
    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[len] < line[i]) {
            dp[++len] = line[i];
        } else if (dp[len] > line[i]) {
            *lower_bound(dp, dp + len, line[i]) = line[i];
        }
    }
    cout << len;
}



