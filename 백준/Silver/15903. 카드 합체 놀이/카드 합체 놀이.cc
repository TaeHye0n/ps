#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}

	while (m--) {
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	ll res = 0;
	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}
	cout << res;
	return 0;
}