#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> crew;
    
    for (string s : timetable) {
        for (char &c : s) {
            if (c == ':') c = ' '; 
        }
        int hr, min;
        stringstream ss;
        ss.str(s);
        ss >> hr; ss >> min;
        
        crew.push_back(hr * 60 + min);
    }
    sort(crew.begin(), crew.end());
    
    int st = 9 * 60;
    int idx = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++, st += t) {
        int cnt = 0;
        bool isFull = false;
        for (int j = idx; j < crew.size(); j++) {
            if (crew[j] <= st) {
                idx++;
                cnt++;
                if (cnt == m) {
                    isFull = true;
                    break;
                }
            }
        }
        if (i == n) {
            if (cnt == m) ans = crew[idx - 1] - 1;
            else ans = st;
        }
    }
    
    int hr = ans/60;
    int min = ans%60;
    
    if (hr < 10) {
        answer = answer + "0" + to_string(hr);
    } else {
        answer = answer + to_string(hr);
    }
    answer = answer + ":";
    if (min < 10) {
        answer = answer + "0" + to_string(min);
    } else {
        answer = answer + to_string(min);
    }
    return answer;
}