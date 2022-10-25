#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
vector<pair<int, int>> score;

int solve() {
    int ans = 1;
    sort(score.begin(), score.end());
    int idx = 0;
    for (int i = 1; i < N; i++) {
        if (score[idx].second > score[i].second) {
            ans++;
            idx = i;
        }
    }
    return ans;
}
int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        score.clear();
        for (int i = 0; i < N; i++) {
            int temp = 0;
            int temp2 = 0;
            cin >> temp >> temp2;
            score.push_back({ temp,temp2 });
        }
        cout << solve() << "\n";
    }
    return 0;
}