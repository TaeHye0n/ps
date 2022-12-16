import java.util.*;

class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        Set<Integer> s1 = new HashSet<>();
        Map<Integer, Integer> s2 = new HashMap<>();
        
        
        for(int i = 0; i < topping.length; i++){
            s2.put(topping[i], s2.getOrDefault(topping[i], 0)+1);
        }
        
        for(int i = 0; i < topping.length; i++){
            s1.add(topping[i]);
            s2.put(topping[i], s2.get(topping[i])-1);
            if(s2.get(topping[i]) == 0){
                s2.remove(topping[i]);
            }
            if(s1.size() == s2.size()) answer++;
        }
        return answer;
    }
}