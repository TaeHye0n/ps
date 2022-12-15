import java.util.*;

class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i = 0; i < score.length; i++){
            if(i+1 <= k){
                pq.add(score[i]);
            }
            
            else if(i+1 > k && pq.peek() < score[i]){
                pq.remove();
                pq.add(score[i]);
            }
            answer[i] = pq.peek();
        }
        
        return answer;
    }
}