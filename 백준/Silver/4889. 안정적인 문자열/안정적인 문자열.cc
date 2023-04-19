#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T = 1;
	while (1) {
		int ans = 0;
		string s;
		cin >> s;
		if (s[0] == '-') break;
		stack<char> st1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '}') {
				if (st1.empty()) {
					ans++;
					st1.push('{');
				}
				else st1.pop();
			}
			else st1.push('{');
		}
		ans += st1.size() / 2;
		cout << T++ << ". " << ans << "\n";
	}
	return 0;
}