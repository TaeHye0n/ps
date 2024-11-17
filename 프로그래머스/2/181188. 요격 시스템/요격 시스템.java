import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        Arrays.sort(targets, (o1 ,o2) -> {
            return o1[1] - o2[1];
        });
        
        int prev = 0;
        for (int i = 0; i < targets.length; i++) {
            if (targets[i][0] >= prev) {
                answer++;
                prev = targets[i][1];
            }
        }
        return answer;
    }
}