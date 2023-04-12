#include <iostream>
#include <string>
#include <climits>
using namespace std;

int N;
int ans = INT_MAX;
string st, ed;
string temp;


void solve() {
	temp = st;
	int cnt = 0;
	temp[0] = (temp[0] == '0') ? '1' : '0';
	temp[1] = (temp[1] == '0') ? '1' : '0';
	cnt++;
	for (int i = 1; i < N; i++) {
		if (temp[i - 1] != ed[i - 1]) {
			cnt++;
			temp[i - 1] = (temp[i - 1] == '0') ? '1' : '0';
			temp[i] = (temp[i] == '0') ? '1' : '0';
			if (i + 1 >= N) continue;
			temp[i + 1] = (temp[i + 1] == '0') ? '1' : '0';
		}
	}
	if (temp == ed) ans = min(ans, cnt);

	temp = st;
	cnt = 0;
	for (int i = 1; i < N; i++) {
		if (temp[i - 1] != ed[i - 1]) {
			cnt++;
			temp[i - 1] = (temp[i - 1] == '0') ? '1' : '0';
			temp[i] = (temp[i] == '0') ? '1' : '0';
			if (i + 1 >= N) continue;
			temp[i + 1] = (temp[i + 1] == '0') ? '1' : '0';
		}
	}
	if (temp == ed) ans = min(ans, cnt);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;
	cin >> st >> ed;
	solve();
	if (ans == INT_MAX) ans = -1;
	cout << ans;
	return 0;
}