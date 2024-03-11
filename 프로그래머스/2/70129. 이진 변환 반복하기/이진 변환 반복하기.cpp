#include <string>
#include <vector>
#include <iostream>

using namespace std;

string makeBinary(int len) {
    string s;
    while(len > 0) {
        s += to_string(len % 2);
        len /= 2;
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer(2);
    
    int cnt = 0;
    while (s != "1") {
        int oneCnt = 0;
        int zeroCnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') zeroCnt++;
            else oneCnt++;
        }
        s = "";
        answer[1] += zeroCnt;
        s = makeBinary(oneCnt);
        cnt++;
    }
    answer[0] = cnt;
    return answer;
}