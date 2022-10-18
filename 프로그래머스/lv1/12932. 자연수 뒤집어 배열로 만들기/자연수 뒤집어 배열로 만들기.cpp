#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int a = 0;
    
    while(n != 0){
    a = n % 10;
    answer.push_back(a);
    n /= 10;
    }
    
    return answer;
}