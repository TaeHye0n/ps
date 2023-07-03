import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        Arrays.sort(targets, (o1,o2)-> {
            return o1[1] - o2[1];
        });
        
        int curr = -1;
        for(int[] target : targets){
            int st = target[0];
            int ed = target[1];
            if(curr <= st){
                answer++;
                curr = ed;
            }            
        }
        return answer;
    }
}