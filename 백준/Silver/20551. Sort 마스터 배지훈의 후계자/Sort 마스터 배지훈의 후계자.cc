#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second
using namespace std;
typedef long long ll;


int N, M; // 1 <= N, M <= 200,000
int arr[200001];
int main() {
    FAST_IO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int i = 0; i < M; i++) {
        int target = 0;
        cin >> target;

        int res = -1;

        int st = 0, ed = N - 1;

        while (st <= ed) {
            int mid = (st + ed) / 2;

            if (arr[mid] < target) {
                st = mid + 1;
            }
            else {
                if (arr[mid] == target) {
                    res = mid;
                }
                ed = mid - 1;
            }
        }
        cout << res << endl;
    }
    
    return 0;
    
}