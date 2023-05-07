#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long ans = 0;
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		ans += abs(i + 1 - v[i]);
	}
	cout << ans;
	return 0;
}