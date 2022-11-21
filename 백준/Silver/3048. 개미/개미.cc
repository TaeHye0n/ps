#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N1, N2, T;
string s1, s2;
void input() {
	cin >> N1 >> N2;
	cin >> s1;
	cin >> s2;
	cin >> T;
}

void solve() {
	reverse(s1.begin(), s1.end());
	string s = s1 + s2;
	while (T--) {
		for (int i = 0; i < N1 + N2 - 1; i++) {
			if (s1.find(s[i]) != string::npos && s2.find(s[i + 1]) != string::npos) {
				swap(s[i], s[i + 1]);
				i++;
			}
		}
	}
	cout << s;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
}