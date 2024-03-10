#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define MAX 200001

using namespace std;
typedef long long ll;

int n;
int dp[MAX];

void input() {
    cin >> n;
}

int main() {
    FAST_IO;
    input();

    int len = 0;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        cin >> temp;
        if (temp > dp[len]) dp[++len] = temp;
        else *lower_bound(dp, dp + len, temp) = temp;
    }
    cout << n - len;

    return 0;
}



