#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a, b;
bool flag;
vector<vector<int>> v(2001);
bool vi[2001];


void dfs(int point, int depth) {
	if (depth == 4) {
		flag = true;
	}
	vi[point] = true;

	for (int i = 0; i < v[point].size(); i++) {
		int np = v[point][i];
		if (vi[np] == false && flag == false) {
			dfs(np, depth + 1);
		}
	}
	vi[point] = false;
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		dfs(i, 0);
		if (flag) break;
	}

	cout << flag;

	return 0;
}