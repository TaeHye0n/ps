#include <iostream>
#include <vector>

using namespace std;


string L, R;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> L >> R;
	
	if (L.length() != R.length()) {
		cout << 0;
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < L.length(); i++) {
		if (L[i] == '8' && L[i] == R[i]) cnt++;
		else if (L[i] != R[i]) break;
	}
	cout << cnt;
	return 0;
}