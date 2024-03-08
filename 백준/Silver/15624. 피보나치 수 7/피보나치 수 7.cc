#include <iostream>
#include <vector>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define MAX 1000001
#define MOD 1000000007

using namespace std;

typedef long long ll;

int n;
ll dp[MAX];

void input() {
    cin >> n;

}

int main() {
    FAST_IO;
    input();
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    cout << dp[n];
}



