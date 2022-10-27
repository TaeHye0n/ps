#include <iostream>
#include <climits>

#define MAX 100001
using namespace std;

int N, S;
int num[MAX] = { 0, };
int ans = INT_MAX;

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
}

void solve() {
	int start = 0, end = 0;
	int val = num[0];
	while (start <= end) {
		if (end == N) break;
		if (val >= S) ans = min(ans, end - start + 1);
		if (val < S) {
			end++;
			val += num[end];
		}
		else {
			val -= num[start];
			start++;
		}
	
	}
	if (ans == INT_MAX) ans = 0;

}
int main() {
	input();
	solve();
	cout << ans;
	return 0;
}