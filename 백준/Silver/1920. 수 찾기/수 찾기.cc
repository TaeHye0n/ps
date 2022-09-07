#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
void solve(int num) {
	bool flag = false;
	int left = 0;
	int right = n - 1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (v[mid] == num) {
			flag = true;
			break;
		}
		else if (v[mid] < num) left = mid + 1;
		else  right = mid - 1;
	}
	if (flag) cout << "1\n";
	else cout << "0\n";
}
void input() {
	cin >> n;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		solve(tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	return 0;
}