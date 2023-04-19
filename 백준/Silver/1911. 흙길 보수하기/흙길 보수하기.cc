#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, L; 
	cin >> N >> L;
	vector<pair<int, int>> pools;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pools.push_back({ a,b });
	}
	sort(pools.begin(), pools.end());
	int answer = 0;
	int cur = 0;
	for (auto p : pools) {
		if (cur >= p.second) continue;
		cur = max(cur, p.first);
		int cnt = (p.second - cur - 1) / L + 1;
		answer += cnt;
		cur += cnt * L;
	}
	cout << answer;
	return 0;
}