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

int n, m; // 1 <= n <= 5000, 1 <= m <= n
int arr[5001];
int ans = INT_MAX;


// 결정문제 mid보다 큰 구간의 최댓값의 개수가 m개 미만인가
bool check(int mid) {
    int cnt = 1;
    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);

        if (maxVal - minVal > mid) {
            cnt++;
            maxVal = arr[i];
            minVal = arr[i];
        }
    }

    return cnt <= m;
}
int main() {
  
    FAST_IO;
 
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0;
    int r = *max_element(arr, arr + n);

    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            if (ans > mid) {
                ans = mid;
            }
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans;
  
    return 0;
    
}