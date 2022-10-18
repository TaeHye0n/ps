#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int start = 1;
    while(start <= n){
        int temp = 0;
        for(int i = start; temp <= n; i++){
            temp += i;
            if(temp == n) answer++;
        }
        start++;
    }
    return answer;
}