#include <iostream>
#include <algorithm>

#define MAX 5000001
using namespace std;

int N, K; // N개의 수 , k번째 수
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cout << arr[K - 1];
	return 0;
}