#include<iostream>
using namespace std;

int A, B, C, M;
int day = 0;
void input() {
    cin >> A >> B >> C >> M;
}

int main() {
    input();
    int answer = 0;
    int fatigue = 0;
    while (day < 24) {
        day++;
        if (fatigue + A > M) {
            if (fatigue - C >= 0) {
                fatigue -= C;
            }
            else fatigue = 0;
            
            continue;
        }

        fatigue += A;
        answer += B;
    }
    cout << answer;
    return 0;
}