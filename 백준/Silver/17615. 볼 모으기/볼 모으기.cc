#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int ans = INT_MAX;
string s;

void calculate(char c) {
	int cnt = 0;
	bool change = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != c) change = true;
		else if (change && s[i] == c) cnt++;
	}
	if (ans > cnt) ans = cnt;
	cnt = 0;
	change = false;

	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] != c) change = true;
		else if (change && s[i] == c) cnt++;
	}
	if (ans > cnt) ans = cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
		
	int N;
	cin >> N;
	cin >> s;
	calculate('R');
	calculate('B');
	cout << ans;
	return 0;
}