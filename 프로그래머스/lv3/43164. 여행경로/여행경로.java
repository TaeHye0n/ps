import java.util.*;

class Solution {  
    private static boolean[] visited;
    private static ArrayList<String> list = new ArrayList<>();
    private static boolean flag;
    
    public String[] solution(String[][] tickets) {
        String[] answer = {};
        visited = new boolean[10001];
        Arrays.sort(tickets, new Comparator<String[]>(){
            @Override
            public int compare(String[] arr1, String[] arr2){
                if(arr1[0].equals(arr2[0])){
                    return arr1[1].compareTo(arr2[1]);
                }
                return arr1[0].compareTo(arr2[0]);
            }
        });
        dfs(tickets, "ICN", 0);
        answer = list.toArray(new String[list.size()]);
        return answer;
    }
    
    public void dfs(String[][] tickets, String st, int cnt){
        if(cnt == tickets.length){
            flag = true;
        }
        list.add(st);
        for(int i = 0; i < tickets.length;i++){
            if(tickets[i][0].equals(st) && !visited[i]){
                visited[i] = true;
                dfs(tickets, tickets[i][1], cnt+1);
                if(!flag){
                    list.remove(list.size()-1);
                    visited[i] = false;
                }
            }
        }
    }
}

 