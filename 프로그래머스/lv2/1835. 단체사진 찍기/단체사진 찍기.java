import java.util.*;
import java.io.*;

class Solution {
    static char[] friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    static boolean[] visited;
    static int answer;
    public int solution(int n, String[] data) {
        visited = new boolean[8];
        answer = 0;
        dfs("",data, 0);
        return answer;
    }
    
    private static void dfs(String str, String[] data, int cnt){
        if(cnt == 8){
            if(check(str, data)) answer++;
            return;
        }
        
        for(int i = 0; i < 8; i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(str+friends[i], data, cnt + 1);
                visited[i] = false;
            }
        }
    }
    private static boolean check(String str, String[] data){
        for(String s : data){
            int dist = Math.abs(str.indexOf(s.charAt(0)) - str.indexOf(s.charAt(2))) - 1;
            // System.out.println(dist);
            char oper = s.charAt(3);
            int value = s.charAt(4) - '0';
            
            if(oper == '='){
                if(dist != value) return false;
            }
            else if(oper == '<'){
                if(dist >= value) return false;
            }
            else if(oper == '>'){
                if(dist <= value) return false;
            }
        }
        return true;
    }
}