import java.io.*;

class Solution {
    static int answer;
    public int solution(int[] picks, String[] minerals) {
        answer = Integer.MAX_VALUE;
        dfs(picks, minerals, 0, 0);
        return answer;
    }
    
    private void dfs(int[] picks, String[] minerals, int stIdx, int cost) {
        if (stIdx >= minerals.length) {
            answer = Math.min(answer, cost);
            return;
        }
        
        boolean flag = true;
        for (int i = 0; i < picks.length; i++) {
            if (picks[i] != 0) {
                flag = false;
                picks[i]--;
                dfs(picks, minerals, stIdx + 5, cost + getCost(i, minerals, stIdx));
                picks[i]++;
            }
        }
        
        if (flag) {
            answer = Math.min(answer, cost);
            return;
        }
    }
    
    private int getCost(int pickIdx, String[] minerals, int stIdx) {
        int cost = 0;
        int power = 1;
        if (pickIdx == 0) {
            power = 25;
        } else if (pickIdx == 1) {
            power = 5;
        }
        
        for (int i = stIdx; i < Math.min(stIdx + 5, minerals.length); i++) {
            String name = minerals[i];
            if (name.equals("diamond")) {
                cost += (25 / power);
            } else if (name.equals("iron")) {
                cost += Math.ceil((5.0 / power));
            } else {
                cost += 1;
            }
        }
        return cost;
    }
}