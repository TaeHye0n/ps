#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		queue<pair<int, int>> q;
		
		vector<bool> visited(n, false);
		int stx, sty;
		cin >> stx >> sty;
		
		int dtx, dty;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			v[i] = { x,y };
		}
		cin >> dtx >> dty;

		q.push({ stx,sty });

		bool isHappy = false;

		while (!q.empty()) {
			int currx = q.front().first;
			int curry = q.front().second;
			q.pop();

			if (currx == dtx && curry == dty) {
				isHappy = true;
				break;
			}

			int dist = abs(dtx - currx) + abs(dty - curry);
			

			if (dist <= 1000) {
				q.push({ dtx,dty });
			}
			else {
				for (int i = 0; i < v.size(); i++) {
					int tempDist = abs(v[i].first - currx) + abs(v[i].second - curry);
					if (tempDist <= 1000 && !visited[i]) {
						q.push({ v[i].first, v[i].second });
						visited[i] = true;
					}
				}
			}
		}

		if (isHappy) cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}