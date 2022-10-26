#include <iostream>

using namespace std;

int N, K;
int schedule[101];
int multiTap[101];
int ans;

void input() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> schedule[i];
    }
}

void solve() {
    for (int i = 0; i < K; i++) {
        bool isPlugged = false;
        for (int j = 0; j < N; j++) {
            if (multiTap[j] == schedule[i]) {
                isPlugged = true;
                break;
            }
        }
        if (isPlugged) continue;

        for (int j = 0; j < N; j++) {
            if (multiTap[j] == 0) {
                multiTap[j] = schedule[i];
                isPlugged = true;
                break;
            }
        }
        if (isPlugged) continue;

        int idx = 0;
        int tempIdx = -1;

        for (int j = 0; j < N; j++) {
            int next = i + 1;
            int finalUseIdx = 0;
            while (next < K && multiTap[j] != schedule[next]) {
                next++;
                finalUseIdx++;
            }
            
            if (finalUseIdx > tempIdx) {
                idx = j;
                tempIdx = finalUseIdx;
            }
        }
        ans++;
        multiTap[idx] = schedule[i];

    }
}

int main() {
    input();
    solve();
    cout << ans;
    return 0;
}