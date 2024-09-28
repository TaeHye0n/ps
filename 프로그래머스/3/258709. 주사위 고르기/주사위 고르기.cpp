#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 1. 주사위 고르는 경우의수 구하기 o(252)개
// 2. 경우의 수 마다 승패 계산 -> 6^n개 방식으로 풀면 시간초과 -> 나올 수 있는 합들을 구한 후 한쪽 기준 이분탐색

int n;
vector<vector<int>> dices;
vector<vector<int>> comb;
vector<int> sumA, sumB;

void make_comb(int idx, vector<int> com) {
    if (com.size() == n / 2) {
        comb.push_back(com);
        return;
    }
    
    for (int i = idx; i < n; i++) {
        com.push_back(i);
        make_comb(i + 1, com);
        com.pop_back();
    }
}

void cal_sum(int idx, int sum, bool isA, vector<int> dice) {
    if (idx == n / 2) {
        if (isA) {
            sumA.push_back(sum);
        } else {
            sumB.push_back(sum);
        }
        return;
    }
    
    for (int i = 0; i < 6; i++) {
        cal_sum(idx + 1, sum + dices[dice[idx]][i], isA, dice);
    }
}

int lower_bound(int target) {
    int l = 0;
    int r = sumB.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (sumB[mid] >= target) r = mid;
        else l = mid + 1;
    }
    
    return l;
}
vector<int> solution(vector<vector<int>> dice) {
    dices = dice;
    n = dice.size();
    vector<int> answer(n / 2);
    vector<int> v;
    make_comb(0, v);
    int max_cnt = 0;
    
    for (int i = 0; i < comb.size(); i++) {
        sumA.clear(); sumB.clear();
        vector<int> diceA = comb[i];
        vector<int> diceB;

        for (int j = 0; j < n; j++) {
            bool isA = false;
            for (int k = 0; k < diceA.size(); k++) {
                if (j == diceA[k]) {
                    isA = true;
                    break;
                }
            }
            if (!isA) diceB.push_back(j);
        }
        
        cal_sum(0, 0, true, diceA);
        cal_sum(0, 0, false, diceB);
        
        sort(sumB.begin(), sumB.end());
        int cnt = 0;
        for (auto sum : sumA) {
            cnt += lower_bound(sum);
        }
        
        if (cnt > max_cnt) {
            max_cnt = cnt;
            
            for (int j = 0; j < n / 2; j++) {
                answer[j] = diceA[j] + 1;
            }
        }
    } 
    return answer;
}