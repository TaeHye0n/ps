import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 100001;
        
        int l = 1;
        int r = 100000;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isValid(diffs, times, limit, mid)) {
                answer = Math.min(answer, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return answer;
    }
    
    boolean isValid(int[] diffs, int[] times, long limit, int level) {
        long amount = times[0];
        
        for (int i = 1; i < diffs.length; i++) {
            if (diffs[i] <= level) {
                amount += times[i];
            } else {
                long timeSum = times[i] + times[i - 1];
                long level_diff = diffs[i] - level;
                amount += level_diff * timeSum;
                amount += times[i];
            }
            if (amount > limit) return false;
        }
        return true;
    }
}