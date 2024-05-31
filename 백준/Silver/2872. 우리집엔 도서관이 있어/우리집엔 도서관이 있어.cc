#include <iostream>
#include <string>
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


int N; // N <= 300,000, 책의 개수]
int arr[300001];

int main() {
    FAST_IO;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int num = N;
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] == num) {
            num--;
        }
    }

    cout << num;
    return 0;
    
}