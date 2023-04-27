#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N;
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}