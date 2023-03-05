#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long getY(int x, int d){
    return sqrt((long long)d*d -((long long)x*x));
}
long long solution(int k, int d) {
    long long answer = 0;
    for(int i = 0; i <= d; i+=k){
        answer += getY(i,d)/k + 1;
    }
    return answer;
}