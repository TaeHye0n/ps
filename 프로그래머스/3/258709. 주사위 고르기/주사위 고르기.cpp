#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
vector<vector<int>> dices;
vector<vector<int>> diceComb;
vector<int> sumA;
vector<int> sumB;
// 주사위 고르기 nC(n/2)
// 중복X 조합
void makeComb(int st, vector<int> cur) {
    if (cur.size() == n / 2) {
        diceComb.push_back(cur);
        return;
    }
    
    for (int i = st; i < n; i++) {
        cur.push_back(i);
        makeComb(i + 1, cur);
        cur.pop_back();
    }
}

void calSum(int idx, int sum, bool isA, vector<int> selectedDices) {
    if (idx == n / 2) {
        isA ? sumA.push_back(sum) : sumB.push_back(sum);
        return;
    }
    
    for (int i = 0; i < 6; i++) {
        calSum(idx + 1, sum + dices[selectedDices[idx]][i], isA, selectedDices);
    }
}
vector<int> solution(vector<vector<int>> dice) {
    dices = dice;
    n = dice.size();
    vector<int> answer(n / 2);
    vector<int> v;
    makeComb(0, v);
    
    int maxCnt = 0;
    for (auto diceA : diceComb) {
        sumA.clear(); sumB.clear();
        vector<int> diceB;
        
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (auto idx : diceA) {
                if (i == idx) flag = true;
            }
            
            if (flag) continue;
            diceB.push_back(i);
        }
        calSum(0, 0, true, diceA);
        calSum(0, 0, false, diceB);
        sort(sumB.begin(), sumB.end());
        
        int cnt = 0;
        for (int sum : sumA) {
            int st = -1;
            int ed = sumB.size();
            
            while (st + 1 < ed) {
                int mid = (st + ed) / 2;
                
                if (sumB[mid] < sum) st = mid;
                else ed = mid;
            }
            cnt += ed;
        }
        
        if (cnt > maxCnt) {
            maxCnt = cnt;
            
            for (int i = 0; i < diceA.size(); i++) {
                answer[i] = diceA[i] + 1;
            }
        }
    }

    
    return answer;
}   