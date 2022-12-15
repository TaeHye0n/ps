import java.util.*;
import java.io.*;

class Solution {
    private static ArrayList<Edge>[] edgeList;
    private static int[] dist;
    
    private static void dijkstra(){
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(1,0));
        while(!pq.isEmpty()){
            Edge edge = pq.poll();
            int index = edge.index;
            int weight = edge.weight;
            
            if(dist[index] < weight) continue;
            
            for(int i = 0; i < edgeList[index].size(); i++){
                int index2 = edgeList[index].get(i).index;
                int weight2 = edgeList[index].get(i).weight;
                if(dist[index2] > weight2 + weight){
                    dist[index2] = weight2 + weight;
                    pq.add(new Edge(index2, dist[index2]));
                }
            }
        }
    }
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        edgeList = new ArrayList[N+1];
        dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        for(int i = 1; i <= N; i++){
            edgeList[i] = new ArrayList<>();
        }
        for(int i = 0; i < road.length; i++){
            edgeList[road[i][0]].add(new Edge(road[i][1], road[i][2]));
            edgeList[road[i][1]].add(new Edge(road[i][0], road[i][2]));
        }
        
        dist[1] = 0;
        dijkstra();
        
        for(int cost: dist){
            if(cost <= K) answer++;
        }
        return answer;
    }
    
    private static class Edge implements Comparable<Edge> {
        int index;
        int weight;
        
        public Edge(int index, int weight){
            this.index = index;
            this.weight = weight;
        }
        
        @Override
        public int compareTo(Edge o){
            return weight - o.weight;
        }
    }
}