#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool check(int log, int hold, int day) {
    if (day == 6 || day == 7) return true;
    
    int h = log / 100;
    int m = log % 100;
    m += h * 60;
    
    int h2 = hold / 100;
    int m2 = hold % 100;
    m2 += h2 * 60;
    m2 += 10;
    if (m > m2) {
        return false;
    } 
    return true;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();
    
    int cur_day = startday;
    
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < timelogs[0].size(); j++) {
            if (!check(timelogs[i][j], schedules[i], cur_day)) {
                flag = false;
            } 
            cur_day++;
            if (cur_day > 7) cur_day = 1;
            if (!flag) break;
        }
        if (flag) answer++;
        cur_day = startday;
    }
    return answer;
}

