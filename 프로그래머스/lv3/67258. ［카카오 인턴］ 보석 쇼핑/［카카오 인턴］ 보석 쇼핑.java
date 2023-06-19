import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        int size = gems.length;
        Set<String> set = new HashSet<>();
        Map<String, Integer> map = new HashMap<>();
        for(String s : gems){
            set.add(s);
        }        
        int left = 0, right = 0;
        int dist = Integer.MAX_VALUE;
        while(true){
            if(set.size() == map.size()){
                map.put(gems[left], map.get(gems[left])-1);
                if(map.get(gems[left]) == 0) map.remove(gems[left]);
                left++;
            }
            else if(right == size) break;
            else{
                map.put(gems[right], map.getOrDefault(gems[right], 0) + 1);
                right++;
            }
            
            if(map.size() == set.size()){
                if(right - left < dist){
                    dist = right - left;
                    answer[0] = left + 1;
                    answer[1] = right;
                }
            }
        }
        return answer;
    }
}