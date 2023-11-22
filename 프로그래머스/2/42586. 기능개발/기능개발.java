import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        
        Queue<Integer> indexQueue = new LinkedList<>();
        
        for (int i = 0; i < progresses.length; i++) {
            indexQueue.offer(i);
        }
        
        while (!indexQueue.isEmpty()) {
            int completedTaskCount = 0;
            for (int i = 0; i < progresses.length; i++) {
                progresses[i] += speeds[i];
            }    
            
            while (!indexQueue.isEmpty() && progresses[indexQueue.peek()] >= 100) {
                indexQueue.poll();
                completedTaskCount++;
            }
            
            if (completedTaskCount >= 1) {
                answer.add(completedTaskCount);
            }
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}