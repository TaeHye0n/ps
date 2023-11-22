import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for (int degree : scoville) {
            minHeap.offer(degree);
        }
        
        while (minHeap.peek() < K) {
            if (minHeap.size() == 1) {
                return -1;
            }
            
            int minDegree = minHeap.poll();
            int secondMinDegree = minHeap.poll();
            int sumDegree = minDegree + (secondMinDegree * 2);
            
            minHeap.offer(sumDegree);
            answer++;
        }
        return answer;
    }
}