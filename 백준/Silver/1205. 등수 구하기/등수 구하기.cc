#include <iostream>
#include <vector>


using namespace std;

int N, myScore, P;

void solve() {
	cin >> N >> myScore >> P;
	vector<int> scores(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> scores[i];
	}

	int cnt = 0;
	int ans = 1;
	for (int i = 1; i <= N; i++) {
		if (myScore < scores[i]) ans++;
		else if (myScore == scores[i]) ans = ans;
		else break;
		cnt++;
	}
	if (cnt == P) ans = -1;
	if (scores.empty()) ans = 1;
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
}