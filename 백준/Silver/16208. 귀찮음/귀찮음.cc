#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define MAX 500001

using namespace std;
typedef long long ll;

int n;
ll a[MAX];
ll len;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        len += a[i];
    }
}

int main() {
    FAST_IO;
    input();
    sort(a, a + MAX);

    ll answer = 0;
    ll idx = 1;
    while (len > 0) {
        len -= a[idx];
        answer += (a[idx++] * len);
    }
    cout << answer;

    return 0;
}

