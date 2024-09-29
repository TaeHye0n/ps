#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;
    
    ll deliver = 0, pickup = 0;
    for (int i = n - 1; i >= 0; i--) {
        deliver += deliveries[i];
        pickup += pickups[i];
        while (deliver > 0 || pickup > 0) {
            answer += (i + 1) * 2;
            deliver -= cap;
            pickup -= cap;
        }
    }
    return answer;
}