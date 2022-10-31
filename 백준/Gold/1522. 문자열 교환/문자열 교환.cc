#include <iostream>
#include <string>

#define INF 987654321	
using namespace std;

string start = "";
int ans = INF;

void input() {
	cin >> start;
}

void solve() {
	int length = 0;
	for (int i = 0; i < start.length(); i++) {
		if (start[i] == 'a') length++;
	}

	for (int i = 0; i < start.length(); i++) {
		int cnt = length;
		int temp = 0;
		for (int j = i; j < i + start.length(); j++) {
			if (!cnt) break;
			if (start[j % start.length()] == 'b') {
				cnt--;
				temp++;
			}
			else cnt--;
		}
		ans = min(ans, temp);
	}
}

int main() {
	input();
	solve();
	cout << ans;
	return 0;
}