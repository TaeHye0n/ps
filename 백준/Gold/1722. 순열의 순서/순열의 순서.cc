#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

bool visited[21];
ll factorial[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, command;
	cin >> N;

	factorial[0] = 1;
	for (int i = 1; i < 21; i++) {
		factorial[i] = factorial[i - 1] * i;
	}

	cin >> command;

	if (command == 1) {
		ll k;

		cin >> k;
		vector<int> v;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[j]) continue;
				if (factorial[N - i] < k) k -= factorial[N - i];
				else {
					v.push_back(j);
					visited[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
	}

	else {
		vector<int> v;
		
		for (int i = 0; i < N; i++) {
			int temp = 0;
			cin >> temp;
			v.push_back(temp);
		}

		ll ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 1; j < v[i]; j++) {
				if(!visited[j]) ans += factorial[N - i - 1];
			}
			visited[v[i]] = true;
		}
		cout << ans + 1;
	}
	return 0;
}