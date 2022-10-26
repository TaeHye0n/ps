#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
vector<int> temp;

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
}

void permute(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			if (i != M - 1) {
				cout << temp[i] << ' ';
			}
			else {
				cout << temp[i] << "\n";
			}
		}
		return;
	}

	for (int i = idx; i < N; i++) {
		temp.push_back(v[i]);
		permute(i, cnt + 1);
		temp.pop_back();
	}
}



int main() {
	input();
	permute(0, 0);
	return 0;
}