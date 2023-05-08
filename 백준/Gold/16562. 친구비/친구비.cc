#include <iostream>
#include <vector>

#define MAX 10001
using namespace std;

int parent[MAX];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y, int cost[]) {
	x = parent[x];
	y = parent[y];
	if (x == y) return;
	if (cost[x] >= cost[y]) {
		parent[x] = y;
	}
	else parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, M, k;
	cin >> N >> M >> k;
	int cost[MAX] = { 0, };
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			int temp = b;
			b = a;
			a = temp;
		}
		if (find(a) != find(b)) {
			merge(a, b, cost);
		}
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (find(i) == i) {
			sum += cost[i];
		}
	}
	if (sum <= k) cout << sum << "\n";
	else cout << "Oh no" << "\n";

	return 0;
}