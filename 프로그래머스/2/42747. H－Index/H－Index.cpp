#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 3 0 6 1 5 -> 0 1 3 5 6
int solution(vector<int> citations) {
    int answer = 0;
    vector<int> c = citations;
    sort(c.begin(), c.end());
    
    for (int i = 0; i < c.size(); i++) {
        int minVal = min(c[i], (int) (c.size() - i));
        answer = max(answer, minVal);
    }
    return answer;
}