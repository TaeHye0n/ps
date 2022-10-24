#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N = 0;
int noodle[10003];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> noodle[i];
    }
}
int solve() {
    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (noodle[i + 1] > noodle[i + 2]) {
            int two = min(noodle[i], noodle[i + 1] - noodle[i + 2]);
            noodle[i] -= two;
            noodle[i + 1] -= two;
            answer += 5 * two;

            int three = min(noodle[i], min(noodle[i + 1], noodle[i + 2]));
            noodle[i] -= three;
            noodle[i + 1] -= three;
            noodle[i + 2] -= three;
            answer += 7 * three;
        }
        else {
            int three = min(noodle[i], min(noodle[i + 1], noodle[i + 2]));
            answer += 7 * three;
            noodle[i] -= three;
            noodle[i + 1] -= three;
            noodle[i + 2] -= three;

            int two = min(noodle[i], noodle[i + 1]);
            answer += 5 * two;
            noodle[i] -= two;
            noodle[i + 1] -= two;
        }

        answer += 3 * noodle[i];
    }
    return answer;
}
int main() {
    input();
    int answer = 0;
    answer = solve();
    cout << answer;
    return 0;
}