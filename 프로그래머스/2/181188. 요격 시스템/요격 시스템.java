import java.io.*;
import java.util.*;

class Solution {
     public int solution(int[][] targets) {
        int answer = 0;
        // 미사일의 개구간(s,e)에서 e를 기준으로 오름차순 정렬
        Arrays.sort(targets, (o1, o2)-> {
            return o1[1] - o2[1];
        });

        // 현재 요격 시스템의 x 좌표
        int curr = -1;
        for(int[] target : targets){
            int st = target[0];
            int ed = target[1];
            // 개구간 이므로 같은 경우에 요격 실패 -> 등호 추가
            if(curr <= st){
                answer++;
                // 새로운 요격 시스템의 x 좌표 설정
                curr = ed;
            }
        }
        return answer;
    }
}