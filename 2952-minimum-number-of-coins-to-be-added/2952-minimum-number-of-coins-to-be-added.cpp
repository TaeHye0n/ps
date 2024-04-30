#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int answer = 0;
        sort(coins.begin(), coins.end());

        //coins의 시작은 1
        int num = 1; // num - 1까지 만들 수 있다
        int idx = 0;
        while (num <= target) {
            if (idx < coins.size() && coins[idx] <= num) {
                num += coins[idx++];
            } else {
                answer++;
                num *= 2;
            }
        }

        return answer;
    }
};