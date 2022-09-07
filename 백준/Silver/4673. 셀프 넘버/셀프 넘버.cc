#include <iostream>
using namespace std;

bool arr[10001];

int main() {
	int n = 1;
	while (n <= 10000) {
		int sum = n;
		int tmp = n;
		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}  
		arr[sum] = true;
		n++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == false) cout << i << "\n";
	}

	return 0;
}