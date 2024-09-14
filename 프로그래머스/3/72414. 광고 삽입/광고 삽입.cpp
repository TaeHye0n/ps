#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
const int MAX = 3600 * 99 + 59 * 60 + 59 + 1;
int arr[MAX];

int get_second(string s) {
    int hour = stoi(s.substr(0, 2));
    int min = stoi(s.substr(3, 2));
    int sec = stoi(s.substr(6 ,2));
    
    return (3600 * hour) + (60 * min) + sec;
}

string get_time_string(int time) {
    string res = "";
    
    int hour = time / 3600; 
    time %= 3600;
    int min = time / 60;
    int sec = time % 60;
    
    res += {hour >= 10 ? to_string(hour) + ":" : ("0" + to_string(hour)) + ":"};
    res += {min >= 10 ? to_string(min) + ":" : ("0" + to_string(min)) + ":"};
    res += sec >= 10 ? to_string(sec) : ("0" + to_string(sec));
    
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int ans = 0;
    int end_second = get_second(play_time);
    int adv_second = get_second(adv_time);
    
    for (string log : logs) {
        int log_start_second = get_second(log.substr(0, 8));
        int log_end_second = get_second(log.substr(9));
        
        // 누적합을 위해 끝 구간 설정
        arr[log_start_second] += 1;
        arr[log_end_second] -= 1;
    }
    
    // 누적합 계산
    for (int i = 0; i < end_second; i++) {
        arr[i + 1] += arr[i];
    }
    
    ll sum = 0;
    // 시작 지점 (00:00:00) 부터 광고 시간 sum 계산
    for (int i = 0; i < adv_second; i++) {
        sum += arr[i];
    }
    
    ll max_sum = sum;
    for (int i = adv_second; i < end_second; i++) {
        sum -= arr[i - adv_second];
        sum += arr[i];
        
        if (sum > max_sum) {
            max_sum = sum;
            ans = i - adv_second + 1;
        }
        
    }
    return get_time_string(ans);
}