#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

typedef long long ll;

ll answer;

int main() {
	FAST_IO;
	answer = 0;
	int n = 0;

	cin >> n;

	int st = 0, ed = 0;
	cin >> st >> ed;

	for (int i = 1; i < n; i++) {
		int l, r; cin >> l >> r;
		if (l < ed) {
			if (r > ed) ed = r;
		}
		else {
			answer += (ed - st);
			st = l;
			ed = r;
		}
	}
	answer += (ed - st);
	cout << answer;
	return 0;
}