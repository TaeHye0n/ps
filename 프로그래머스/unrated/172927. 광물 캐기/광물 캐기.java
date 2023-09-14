import java.util.*;
import java.util.stream.*;
import java.io.*;

class Solution {
    static List<Integer> cost = new ArrayList<>();
    static List<String> minerals;
    static int[] picks;
    static int answer = Integer.MAX_VALUE;
    public int solution(int[] pick, String[] mineral) {
        minerals = Arrays.stream(mineral).collect(Collectors.toList());
        picks = pick;

        for (String s : minerals) {
            if (s.equals("diamond")) cost.add(25);
            else if (s.equals("iron")) cost.add(5);
            else cost.add(1);
        }
        dfs(0,0);
        return answer;
    }
    
    private void dfs(int idx, int res) {
        if ((picks[0] == 0 && picks[1] == 0 && picks[2] == 0) || idx * 5 >= minerals.size()) {
            answer = Math.min(answer, res);
            return;
        }
        
        for (int i = 0; i < 3; i++) {
            if (picks[i] == 0) continue;
            picks[i]--;
            dfs(idx + 1, res + cal(idx, i));
            picks[i]++;
        }
    }
    
    private int cal(int idx, int pickNum) {
        int value = 0;
        int res = 0;
        if (pickNum == 0) value = 25;
        else if (pickNum == 1) value = 5;
        else value = 1;
        
        for (int i = idx * 5; i < cost.size() && i < (idx+1)*5; i++) {
            res += cost.get(i)/value == 0 ? 1 : cost.get(i)/value;
        }
        return res;
    }
}