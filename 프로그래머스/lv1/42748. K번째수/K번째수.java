import java.util.*;

class Solution {
    ArrayList<Integer> nums;
    
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for(int i = 0; i < commands.length; i++){
            int st = commands[i][0];
            int ed = commands[i][1];
            int idx = commands[i][2];
            
            nums = new ArrayList<>();
            for(int j = st-1; j < ed; j++){
                nums.add(array[j]);
            }
            nums.sort(Comparator.naturalOrder());
            answer[i] = nums.get(idx-1);
        }
        return answer;
    }
}