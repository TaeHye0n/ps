import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int degree: scoville){
            pq.add(degree);
        }
        
        while(pq.peek() < K){
            if(pq.size() == 1){
                answer = -1;
                break;
            }
            
            int temp1 = pq.peek();
            pq.remove();
            
            int temp2 = pq.peek();
            pq.remove();
            
            int temp3 = temp1 + (temp2*2);
            pq.add(temp3);
            answer++;
        }
        return answer;
    }
}