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
		stack<char> st2;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '}') {
				if (st1.empty()) {
					ans++;
					st1.push('{');
				}
				else st1.pop();
			}
			else if (s[i] == ')') {
				if (st2.empty()) {
					ans++;
					st2.push('(');
				}
				else st2.pop();
			}
			else if (s[i] == '{')st1.push('{');
			else st2.push('(');
		}

		ans += st1.size() / 2;
		ans += st2.size() / 2;
		cout << T++ << ". " << ans << "\n";
	}
	return 0;
}