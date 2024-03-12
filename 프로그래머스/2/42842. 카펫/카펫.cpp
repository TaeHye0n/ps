#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    
    for (int h = 3; h <= sum; h++) {
        int w = sum / h;
        int yl = (w - 2) * (h - 2);
        int br = sum - yl;
        if (yl == yellow && br == brown) {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    return answer;
}