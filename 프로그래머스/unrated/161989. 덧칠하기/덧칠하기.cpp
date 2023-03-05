#include <string>
#include <vector>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int temp = 0;
    int length = 0;
    for(int i = 0; i < section.size(); i++){
        if(section[i] <= length) continue;
        temp = section[i];
        length = temp + m - 1;
        answer++;
    }
    return answer;
}