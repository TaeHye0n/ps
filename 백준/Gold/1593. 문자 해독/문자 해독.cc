#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

typedef long long ll;

int n, m;
string s, w;
int a_cnt[101];
int main() {
	FAST_IO;

	cin >> n >> m;

	cin >> s >> w;


	for (int i = 0; i < n; i++) {
		char c = s[i];
		a_cnt[c - 'A']++;
	}

	int l = 0, r = n;
	int answer = 0;
	for (int i = l; i < r; i++) {
		a_cnt[w[i] - 'A']--;
	}

	while (r <= m) {
		bool flag = false;
		for (int i = 0; i < 101; i++) {
			if (a_cnt[i] > 0) {
				flag = true;
			}
		}
			if (!flag) answer++;

			a_cnt[w[l++] - 'A']++;
			a_cnt[w[r++] - 'A']--;
	}
	
	cout << answer;
	return 0;
}