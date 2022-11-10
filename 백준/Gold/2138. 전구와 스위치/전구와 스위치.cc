#include <iostream>
#include <string>
#include <climits>

using namespace std;

string st, ed;
string temp;
int N;
int ans = INT_MAX;

void input() {
	cin >> N;
	cin >> st >> ed;
}
void lightChange(int idx) {
	if (idx > 0) temp[idx - 1] = (temp[idx - 1] == '0') ? '1' : '0';
	temp[idx] = (temp[idx] == '0') ? '1' : '0';
	if (idx < N - 1) temp[idx + 1] = (temp[idx + 1] == '0') ? '1' : '0';
}
void solve(int start) {
	temp = st;
	int cnt = 0;
	if (start == 0) {
		lightChange(0);
		cnt++;
	}
	for (int i = 1; i < N; i++) {
		if (temp[i - 1] != ed[i - 1]) {
			lightChange(i);
			cnt++;
		}
	}
	if (temp == ed) ans = min(ans, cnt);
}

int main() {
	input();
	solve(0);
	solve(1);
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
	return 0;
}