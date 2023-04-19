#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long fib[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
		
	int T;
	cin >> T;

	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= 49; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	while (T--) {
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 49; i >= 0; i--) {
			if (n >= fib[i] && n != 0) {
				v.push_back(fib[i]);
				n -= fib[i];
			}
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}