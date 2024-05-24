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
int arr1[1000001];
int arr2[1000001];
int main() {
    FAST_IO;

    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0; cin >> n;
        memset(arr1, 0, sizeof(arr1));
        memset(arr2, 0, sizeof(arr2));
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        int m = 0; cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        sort(arr1, arr1 + n);
        
        for (int i = 0; i < m; i++) {
            int val = arr2[i];
            int l = 0;
            int r = n - 1;
            bool flag = false;
            while (l <= r) {
                int mid = (l + r) / 2;

                if (val < arr1[mid]) r = mid - 1;
                else {
                    if (val == arr1[mid]) {
                        flag = true;
                        cout << 1 << endl;
                        break;
                    }
                    l = mid + 1;
                }
            }
            if (!flag) cout << 0 << endl;
        }

    }
    return 0;
    
}