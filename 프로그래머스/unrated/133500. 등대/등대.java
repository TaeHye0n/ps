import java.io.*;
import java.util.*;

class Solution {
    static int N;
    static int answer = 0;
    static boolean[] light;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    public int solution(int n, int[][] lighthouse) {
        N = n;
        light = new boolean[N+1];
        for(int i = 0; i <= N; i++){
            graph.add(new ArrayList<>());
        }
        for(int i = 0; i < lighthouse.length; i++){
            int from = lighthouse[i][0];
            int to = lighthouse[i][1];
            graph.get(from).add(to);
            graph.get(to).add(from);
        }
        
        dfs(1,1);
        return answer;
    }
    private static void dfs(int cur, int parent){
        for(int i = 0; i < graph.get(cur).size(); i++){
            int next = graph.get(cur).get(i);
            if(next != parent){
                dfs(next, cur);
                if(!light[next] && !light[cur]){
                    light[cur] = true;
                    answer++;
                }
            }
        }
    }
}