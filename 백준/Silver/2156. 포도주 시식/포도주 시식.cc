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


int n;
int arr[10001];
int dp[10001]; // idx 번째 위치까지 가장 많은 포도주를 마신 양

int main() {
    FAST_IO;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        // 1. i번째 포도주를 마시지 않는 경우
        // 2. i번째 포도주를 마시는 경우
        // 2-1. dp[i-1]이 아닌 dp[i-2]인 이유는 dp[i-1]은 i-2, i-1 과 같이 2번 연달아 마신 경우가 포함되어 있기 때문
        // 2-2. dp[i-3]을 사용한 이유는 i-1, i를 연속으로 마신 포도주의 양도 계산해야 하기 때문
        dp[i] = max(dp[i - 1], max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
    }
    cout << dp[n];
    return 0;
}

