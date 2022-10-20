#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a){
        if(n%a == 0){
            n = (n/a)*b;
            answer += n;
        }
        else{
            answer += (n/a)*b;
            n = (n/a)*b + n%a;
        }
    }
    return answer;
}