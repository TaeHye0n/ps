import java.util.*;

class Solution {
    public int solution(int[] stones, int k) {
        int answer = 0;
        int min = 1;
        int max = 200000000;
        
        while (min <= max) {
            int mid = (min + max) / 2;
            
            if (canPass(stones, k, mid)) {
                min = mid + 1;
                answer = Math.max(answer, mid);
            } else {
                max = mid - 1;
            }
        }
        return answer;
    }
    
    private boolean canPass(int[] stones, int k, int cnt) {
        int pass = 0;
        
        for (int stone : stones) {
            if (stone - cnt < 0) pass++;
            else pass = 0;
            
            if (pass >= k) return false;
        }
        return true;
    }
}