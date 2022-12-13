import java.util.*;
import java.io.*;

class Solution {
    
    boolean vi[] = new boolean[51];
    int answer = 100;
    public int solution(String begin, String target, String[] words) {
        dfs(begin, target, words, 0);
        if(answer == 100) answer = 0;
        return answer;
    }
    
    public void dfs(String begin, String target, String[] words, int tmp){
        if(begin.equals(target)){
            if(answer >= tmp) answer = tmp;
            return;
        }
        
        for(int i = 0; i < words.length; i++){
            int cnt = 0;
            for(int j = 0; j < words[i].length(); j++){
                if(begin.charAt(j) != words[i].charAt(j)) cnt++;
                if(cnt == 2) break;
            }
            if(cnt == 1){
                if(!vi[i]){
                    vi[i] = true;
                    dfs(words[i], target, words, tmp+1);
                    vi[i] = false;
                }
            }
        }
    }
}