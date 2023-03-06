#include <string>
#include <vector>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0){
        int curr = storey % 10;
        int next = (storey/10) %10;
        if(curr > 5){
            answer += (10-curr);
            storey += 10;
        }
        else if(curr == 5){
            if(next >= 5){
                answer +=(10-curr);
                storey += 10;
            }
            else {
                answer += curr;
            }
        }
        else {
            answer += curr;
        }
        storey /= 10;
    }
    return answer;
}