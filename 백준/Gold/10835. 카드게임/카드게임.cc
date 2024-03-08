#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define MAX 2001

int N;
int A[MAX];
int B[MAX];
int dp[MAX][MAX];

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
}

int func(int l, int r) {
    if (l > N || r > N) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    dp[l][r] = 0;
    dp[l][r] = max(func(l + 1, r), func(l + 1, r + 1));
    if (A[l] > B[r]) dp[l][r] = max(dp[l][r], func(l, r + 1) + B[r]);

    return dp[l][r];
}

int main() {
    FAST_IO;
    input();
    memset(dp, -1, sizeof(dp));
    cout << func(1, 1);

}


