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
 
    int n = 0, m = 0;

    while (1) {
        int answer = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        int l = 0, r = 0;
        for (; l < n && r < m;) {
            int val1 = arr1[l];
            int val2 = arr2[r];

            if (val1 == val2) {
                l++; r++;
                answer++;
            }

            if (val1 < val2) {
                l++;
            }
            else if (val1 > val2) {
                r++;
            }
        }

        cout << answer << endl;
    }
  
  
    return 0;
    
}