import java.util.*;

class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        
        for(int i = 1; i <= number; i++){
            int temp = getNumber(i);
            if(temp > limit) answer += power;
            else answer += temp;
        }
        return answer;
    }
    
    private static int getNumber(int n){
        int cnt = 0;
        
        for(int i = 1; i*i<=n; i++){
            if(n%i == 0) {
                cnt++;
                if(i*i < n) cnt++;
            }
        }
        
        return cnt;
    }
}