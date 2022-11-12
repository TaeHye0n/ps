#include <iostream>

using namespace std;
const int MAX = 1e5;
int N;
int A[MAX + 1];
int tree[MAX * 4 + 1];
int M;

int minIndex(int a, int b) {
	if (A[a] == A[b]) return a < b ? a : b;
	return A[a] < A[b] ? a : b;
}
int init(int st, int ed, int node) {
	if (st == ed) return tree[node] = st;
	int mid = (st + ed) / 2;
	return tree[node] = minIndex(init(st, mid, node * 2), init(mid + 1, ed, node * 2 + 1));
}

int update(int st, int ed, int node, int idx) {
	if (idx < st || idx > ed || st == ed) return tree[node];

	int mid = (st + ed) / 2;
	return tree[node] = minIndex(update(st, mid, node * 2, idx), update(mid + 1, ed, node * 2 + 1, idx));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	init(0, N - 1, 1);
	while (M--) {
		int q = 0, i = 0, v = 0;
		cin >> q;
		if (q == 2) {
			cout << tree[1] + 1 << "\n";
		}
		else if (q == 1) {
			cin >> i >> v;
			i--;
			A[i] = v;
			update(0, N - 1, 1, i);
		}
	}
	return 0;
}