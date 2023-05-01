#include <iostream>

#define MAX 500001
using namespace std;

int n, m;
int parent[MAX];

int find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) {
			cout << i;
			return 0;
		}
		else Union(a, b);
	}
	cout << 0;

	return 0;
}