#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define MAX 500001

using namespace std;

int n;
int a[MAX];
int len;

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

    int answer = 0;
    int idx = 1;
    while (len > 0) {
        len -= a[idx];
        answer += (a[idx++] * len);
    }
    cout << answer;
}
