import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        int jewelsCount = (int)Arrays.stream(gems)
            .distinct()
            .count();
        
        Map<String, Integer> map = new HashMap<>();
        Queue<String> queue = new LinkedList<>();
        
        int dist = Integer.MAX_VALUE;
        int start = 1;
        for(String gem : gems){
            map.put(gem, map.getOrDefault(gem, 0) + 1);
            queue.offer(gem);
            
            while(map.get(queue.peek()) > 1){
                String str = queue.poll();
                map.put(str, map.get(str) - 1);
                start++;
            }
            
            if(map.size() == jewelsCount && dist > queue.size()){
                dist = queue.size();
                answer[0] = start;
                answer[1] = start + dist - 1;
            }
        }
        return answer;
    }
}