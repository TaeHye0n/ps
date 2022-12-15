import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int i = 0; i < tangerine.length; i++){
            hm.put(tangerine[i], hm.getOrDefault(tangerine[i],0)+1);
        }
        
        List<Integer> valueList = new ArrayList<>(hm.values());
        valueList.sort(new Comparator<Integer>(){
            @Override
            public int compare(Integer o1, Integer o2){
                return o2.compareTo(o1);
            }
        });
        
        while(k>0){
            k = k - valueList.get(0);
            valueList.remove(0);
            answer++;
        }
        
        return answer;
    }
}