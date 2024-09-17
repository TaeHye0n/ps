#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define first Y
#define second X
#define endl "\n"

using namespace std;
typedef long long ll;

int t;
int n, m;
vector<int> a_sum, b_sum;
int a[1001], b[1001];

int lower_bound(int target) {
    int l = 0, r = (int) b_sum.size();

    while (l < r) {
        int mid = (l + r) / 2;
        if (b_sum[mid] >= target) r = mid;
        else l = mid + 1;
    }

    return l;
}

int upper_bound(int target) {
    int l = 0, r = (int) b_sum.size();

    while (l < r) {
        int mid = (l + r) / 2;
        if (b_sum[mid] > target) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main() {
    FAST_IO;

    ll ans = 0;
    cin >> t >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            a_sum.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = i; j < m; j++) {
            sum += b[j];
            b_sum.push_back(sum);
        }
    }

    sort(b_sum.begin(), b_sum.end());

    for (int i = 0; i < a_sum.size(); i++) {
        int target = t - a_sum[i];
        int lower_idx = lower_bound(target);
        int upper_idx = upper_bound(target);

        ans += (upper_idx - lower_idx);
    }

    cout << ans;
    return 0;
}

