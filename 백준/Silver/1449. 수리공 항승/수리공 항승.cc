#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int ans = 1;
vector<int> leak;
void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		leak.push_back(value);
	}
}

void solve() {
	sort(leak.begin(), leak.end());
	for (int i = 0; i < N-1; i++) {
		int sum = 0;
		for (int j = i+1; j < N; j++) {
			sum = leak[j] - leak[i] + 1;
			if (sum > L) {
				ans++;
				i = j - 1;
				break;
			}
		}
	}
}

int main() {
	input();
	solve();
	cout << ans;
	return 0;
}