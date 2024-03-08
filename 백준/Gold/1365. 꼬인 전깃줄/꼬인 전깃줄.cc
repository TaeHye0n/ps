#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define MAX 100001

int n;
int line[MAX];
int dp[MAX];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> line[i];
    }
}

int binarySearch(int l, int r, int val) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (val <= dp[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
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
            int l = binarySearch(1, len, line[i]);
            dp[l] = line[i];
        }
    }
    cout << n - len;
}



