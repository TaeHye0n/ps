#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(9);
vector<int> ans;

void recur(int idx, int sum, int cnt) {
	if (cnt == 7) {
		if (sum == 100) {
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << "\n";
			}
			exit(0);
		}
		return;
	}
	if (idx >= 9) return;

 	ans.push_back(v[idx]);
	recur(idx + 1, sum + v[idx], cnt + 1);
	ans.pop_back();
	recur(idx + 1, sum, cnt);

}

void solve() {
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
	}
	recur(0, 0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
	return 0;
}