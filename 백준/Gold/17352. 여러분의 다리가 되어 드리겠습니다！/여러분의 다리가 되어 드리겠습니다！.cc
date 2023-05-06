#include <iostream>
using namespace std;

int parent[300001];
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int temp = 0;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N - 2; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b)) {
			merge(a, b);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (find(i) != find(j)) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}