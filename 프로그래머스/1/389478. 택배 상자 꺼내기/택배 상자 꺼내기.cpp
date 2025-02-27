#include <string>
#include <vector>
#include <iostream>

using namespace std;

int box[120][120];

int solution(int n, int w, int num) {
    int answer = 0;
    int x = 0;
    int y = 0;
    int cnt = 0;
    int number = 0;
    bool right = true;
    while (number < n) {
        if (cnt == w) {
            cnt = 0;
            if (right) {
                right = !right;
                box[++y][--x] = number;
            } else {
                right = !right;
                box[++y][++x] = number;
            }
            continue;
        } 
        if (right) {
            box[y][x++] = ++number;
            cnt++;
        } else {
            box[y][x--] = ++number;
            cnt++;
        }
    }
    int py, px;
    
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 120; j++) {
            if (box[i][j] == num) {
                py = i;
                px = j;
            }
        }
    }
    
    for (int i = py; i < 120; i++) {
        if (box[i][px] != 0) answer++;
    }
    
    return answer;
}