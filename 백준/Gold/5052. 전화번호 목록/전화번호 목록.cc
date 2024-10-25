#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second

using namespace std;
typedef long long ll;


int main() {
	FAST_IO;
	int t = 0;
	cin >> t;

	while (t-- > 0) {
		int n = 0;
		cin >> n;
		vector<string> input;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			input.push_back(str);
		}
		
		sort(input.begin(), input.end());


		bool flag = true;
		for (int i = 0; i < input.size() - 1; i++) {
			int len = input[i].size();

			if (input[i + 1].substr(0, len) == input[i]) {
				flag = false;
				break;
			}
		}


		if (flag) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;

	}
	return 0;
}