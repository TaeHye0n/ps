import java.util.*;
import java.io.*;


class Solution {
    int answer = 0;
    public int solution(int[] numbers, int target) {
        dfs(numbers, target, 0, -numbers[0]);
        dfs(numbers, target, 0 ,numbers[0]);
        return answer;
    }
    
    public void dfs(int[] numbers, int target, int depth, int sum){
        if(depth == numbers.length-1){
            if(sum == target){
                answer++;
            }
            return;
        }
        
        dfs(numbers, target, depth+1, sum+numbers[depth+1]);
        dfs(numbers, target, depth+1, sum-numbers[depth+1]);
    }
}