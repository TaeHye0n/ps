#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m1;
    map<string, int> m2;
    int n = discount.size();
    
    for (int i = 0; i < want.size(); i++) {
        m1[want[i]] = number[i];
    }
    
    int idx = 0;
    while(1) {
        bool flag = true;
        if (idx + 10 > n) break;
        m2.clear();
        for (int i = idx; i < idx + 10; i++) {
            m2[discount[i]]++;
        }
        
        for (string s : want) {
            if (m1[s] != m2[s]) {
                flag = false;
                break;
            }
        }
        
        if (flag) answer++;        
        idx++;
    }
    return answer;
}