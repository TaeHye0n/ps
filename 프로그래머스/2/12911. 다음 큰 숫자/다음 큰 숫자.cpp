#include <string>
#include <vector>
#include <iostream>

using namespace std;

int countOneFromBinary(int n) {
    int count = 0;
    while (n > 0) {
        int r = n % 2;
        if (r == 1) count++;
        n /=2;
    }
    return count;
}
int solution(int n) {
    int answer = 0;
    int count = countOneFromBinary(n);
    for (int i = n + 1; i <= 1000000; i++) {
        if (count == countOneFromBinary(i)) return i;
    }
    return answer;
}