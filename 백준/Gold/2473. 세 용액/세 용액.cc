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

ll n;
ll arr[5010];
ll result = 3000000001;
int main() {
    FAST_IO;

    cin >> n;
    vector<ll> ans(3);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    // i < n - 2 인 이유는 index가 i 이상인 3개의 용액을 선택하기 때문
    for (ll i = 0; i < n - 2; i++) {
        ll l = i + 1;
        ll r = n - 1;

        while (l < r) {
            ll sum = arr[i] + arr[l] + arr[r];

            // 합이 0에서 더 가까울 떄
            if (abs(sum) < abs(result)) {
                result = abs(sum);
                ans[0] = arr[i];
                ans[1] = arr[l];
                ans[2] = arr[r];
            }

            if (sum < 0) l++;
            else r--;
        }
    }

    for (auto num : ans) {
        cout << num << " ";
    }

    return 0;
    
}