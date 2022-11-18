#include <iostream>
#include <vector>

using namespace std;


void solve() {
	string s;
	cin >> s;
	int arraySize = ')' - '\0' + 1;
	vector<int> cnt(arraySize);
	int ans = 0;
	int total = 0;

	for (char c : s) cnt[c]++;

	if (cnt['('] > cnt[')']) {
		for (char c : s) {
			if (c == '(') {
				ans++;
				total++;
			}
			else {
				total--;
				if (total == 0) ans = 0;
			}
		}
		cout << ans;
	}
	else {
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == ')') {
				ans++;
				total++;
			}
			else {
				total--;
				if (total == 0) ans = 0;
			}
		}
		cout << ans;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();

	return 0;
}