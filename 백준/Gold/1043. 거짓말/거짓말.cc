#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int parents[51];
vector<int> people;
vector<vector<int>> party(51);


int find(int x) {
	if (parents[x] == x) return x;
	return x = find(parents[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	parents[x] = y;
}

void solve() {
	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++) {
		int temp = 0;
		cin >> temp;
		people.push_back(temp);
	}
	
	for (int i = 1; i <= N; i++) parents[i] = i;

	for (int i = 0; i < M; i++) {
		int temp = 0;
		cin >> temp;
		int num = 0, prev = 0;
		for (int j = 1; j <= temp; j++) {
			if (j > 1) {
				prev = num;
				cin >> num;
				Union(prev, num);
			}
			else cin >> num;
			party[i].push_back(num);
		}
	}

	for (auto Party : party) {
		bool flag = false;
		for (auto person : Party) {
			if (flag) break;
			for (auto know : people) {
				if (find(person) == find(know)) {
					flag = true;
					break;
				}
			}
		}
		if (flag) M--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	solve();

	cout << M;
	return 0;
}