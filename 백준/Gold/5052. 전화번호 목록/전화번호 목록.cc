#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> v;
int n;

void input() {
	cin >> n;
	for (int j = 0; j < n; j++) {
		string temp = "";
		cin >> temp;
		v.push_back(temp);
	}
}

int main() {
   
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		bool flag = true;
		input();
		sort(v.begin(), v.end());

		for (int j = 0; j < v.size() - 1; j++) {
			int length = v[j].length();
			int length2 = v[j + 1].length();

			if (length > length2) continue;
			if (v[j + 1].substr(0, length) == v[j]) {
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		v.clear();
	}
	return 0;
}