#include <iostream>

using namespace std;

int N, K;

void input() {
    cin >> N >> K;
}

int main() {
    input();
    int sum = 0;
    for (int i = 0; i < K; i++) {
        sum += i + 1;
    }
    N -= sum;

    if (N < 0) cout << -1;
    else {
        if (N % K == 0) cout << K - 1;
        else cout << K;
    }

    return 0;
}