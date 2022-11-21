#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;

void solve() {
	cin >> N;
	vector<string> st(N);
	vector<string> ed(N);

	for (int i = 0; i < N; i++) {
		cin >> st[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> ed[i];
	}

	int idx = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (ed[i] != st[idx]) {
			ans++;
			for (int j = 0; j < N; j++) {
				if (ed[i] == st[j]) {
					st.erase(st.begin() + j);
					break;
				}
			}
		}
		if (ed[i] == st[idx]) idx++;
	}
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
}