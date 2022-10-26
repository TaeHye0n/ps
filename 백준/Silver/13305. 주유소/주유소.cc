#include <iostream>

using namespace std;

int N;
int road[1000001];
int cost[1000001];
long long ans;
int nextIdx = 0;

void input() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> road[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
}

void findCheap(int idx) {
    for (int i = idx+1; i < N - 1; i++) {
        if (cost[idx] > cost[i]) {
            nextIdx = i;
            break;
        }
    }
}

long long calculateDist(int idx, int nextIdx) {
    long long sum = 0;
    for (int i = idx; i < nextIdx; i++) {
        sum += road[i];
    }
    return sum;
}

void solve() {
    int idx = 0;
    for (int i = idx; i < N-1;) {
        long long dist = 0;
        findCheap(i);
        if (i != nextIdx) {
            dist = calculateDist(i, nextIdx);
            ans += cost[i] * dist;
            i = nextIdx;
        }
        else {
            dist = calculateDist(i, N - 1);
            ans += cost[i] * dist;
            break;
        }
    }
}

int main() {
    input();
    solve();
    cout << ans;
    return 0;
}