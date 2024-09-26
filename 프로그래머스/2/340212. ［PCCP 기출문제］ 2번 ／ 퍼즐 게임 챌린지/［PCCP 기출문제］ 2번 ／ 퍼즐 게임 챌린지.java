import java.util.*;
import java.io.*;

class Solution {
    
    static int[] diffs;
    static int[] times;
    static long limit;
    static int ans = Integer.MAX_VALUE;
    static int n;
    public int solution(int[] diffs2, int[] times2, long limit2) {
        diffs = diffs2; times = times2; limit = limit2;
        n = diffs.length;
        int l = 1;
        int r = 100000;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                ans = Math.min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    static boolean check(int mid) {
        long time = times[0];
        
        for (int i = 1; i < n; i++) {
            if (mid >= diffs[i]) {
                time += times[i];
            } else {
                long diff = diffs[i] - mid;
                long timeSum = times[i] + times[i-1];
                time += (diff * timeSum);
                time += times[i];
            }
        }
        
        if (time > limit) return false;
        return true;
    }
}