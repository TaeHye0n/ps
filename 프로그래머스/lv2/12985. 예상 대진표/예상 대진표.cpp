#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while(a != b){
        answer++;
        if(a % 2 != 0) a = a/2 + 1;
        else a /= 2;
        if(b % 2 != 0) b = b/2 +1;
        else b /= 2;
    }
    
    return answer;
}