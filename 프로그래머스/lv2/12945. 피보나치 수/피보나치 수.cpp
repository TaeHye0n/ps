#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    int tmp = 0;
    for(int i = 2; i <= n; i++){
        tmp = (v[i-2] + v[i-1]) % 1234567;
        v.push_back(tmp);
    }
    answer = v.back();
    return answer;
}