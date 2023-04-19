#include <iostream>
#include <vector>

using namespace std;

int N, M; // 가로 세로
int ea; // 상점의 개수
vector<pair<int, int>> store;
pair<int, int> myPos;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cin >> ea;

	for (int i = 0; i < ea; i++) {
		int a, b; // a 1,2,3,4 = 북 남 서 동
		cin >> a >> b;
		store.push_back({ a,b });
	}

	int a, b;
	cin >> a >> b;
	myPos = { a,b };
	int sum = 0;
	int curdir = myPos.first;
	int curlen = myPos.second;
	
	for (int i = 0; i < ea; i++) {
		if (curdir == store[i].first) sum += abs(curlen - store[i].second);

		else if (curdir == 1 || curdir == 2) {
			if (store[i].first == 3 || store[i].first == 4) {
				if (store[i].first == 3) sum += curlen;
				else sum += N - curlen;

				if (curdir == 1) sum += store[i].second;
				else sum += (M - store[i].second);
			}
			else {
				int temp1 = M + store[i].second + curlen;
				int temp2 = M + 2 * N - curlen - store[i].second;
				sum += min(temp1, temp2);
			}
		}
		else {
			if (store[i].first == 1 || store[i].first == 2) {
				if (store[i].first == 1) sum += curlen;
				else sum += M - curlen;

				if (curdir == 3) sum += store[i].second;
				else sum += (N - store[i].second);
			}
			else {
				int temp1 = N + store[i].second + curlen;
				int temp2 = N + 2 * M - store[i].second - curlen;
				sum += min(temp1, temp2);
			}
		
		}
	}
	cout << sum;
	return 0;
}