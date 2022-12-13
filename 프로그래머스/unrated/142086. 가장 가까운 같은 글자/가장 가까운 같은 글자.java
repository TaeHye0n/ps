import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        
        HashMap<Character, Integer> hm = new HashMap<>();
        
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(!hm.containsKey(c)){
                answer[i] = -1;
                hm.put(c,i);
            }
            else{
                answer[i] = i - hm.get(c);
                hm.put(c,i);
            }
        }
        return answer;
    }
}