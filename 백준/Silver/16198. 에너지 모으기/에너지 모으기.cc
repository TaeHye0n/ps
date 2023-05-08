#include <iostream>
#include <vector>
using namespace std;

int N;
int ans;

void dfs(vector<int> v, int total) {
	if (v.size() == 2) {
		ans = max(ans, total);
	}

	for (int i = 1; i < v.size() - 1; i++) {
		vector<int> temp;
		int sum = 0;
		sum = v[i - 1] * v[i + 1];
		for (int j = 0; j < v.size(); j++) {
			if (j == i) continue;
			temp.push_back(v[j]);
		}
		dfs(temp, total+sum);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	dfs(v, 0);
	cout << ans;
	return 0;
}