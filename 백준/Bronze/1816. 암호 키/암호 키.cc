#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
long long S;
long long arr[11];

vector<int> v;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}
bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

string isYES(long long n) {
	for (int i = 0; i < v.size(); i++) {
		if (n % v[i] == 0) return "NO";
	}
	return "YES";
}
int main() {
	input();
	for (int i = 1; i <= 1000000; i++) {
		if (isPrime(i)) v.push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		cout << isYES(arr[i]) << "\n";
	}
	
	return 0;
}