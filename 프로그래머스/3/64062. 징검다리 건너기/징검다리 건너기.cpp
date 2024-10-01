#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int l = 0, r = 200000000;
    
    while (l <= r) {
        vector<int> temp = stones;
        int jump = 0;
        int max_jump = 0;
        int mid = (l + r) / 2;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] - mid < 0) {
                jump++;
            } else {
                jump = 0;
            }
            max_jump = max(max_jump, jump);
        }
        
        if (max_jump >= k) {
            r = mid - 1;
        } else {
            answer = max(answer, mid);
            l = mid + 1;
        }
        
    }
    return answer;
}