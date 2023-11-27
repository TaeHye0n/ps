import java.util.*;
import java.io.*;

class Solution {
    static Map<String, List<Integer>> map = new HashMap<>();
    public int[] solution(String[] infos, String[] queries) {
        int[] answer = new int[queries.length];
        
        for(String info : infos){
            dfs("", info.split(" "), 0);
        }
        
        for(String key : map.keySet()){
            Collections.sort(map.get(key));
        }
        
        int idx = 0;
        for(String query : queries){
            String[] arr = query.replaceAll(" and ", " ").split(" ");
            String str = arr[0]+arr[1]+arr[2]+arr[3];
            int score = Integer.parseInt(arr[4]);
            if(map.containsKey(str)){
                int left = 0;
                int right = map.get(str).size() - 1;
                while(left <= right){
                    int mid = (left + right)/2;
                    if(map.get(str).get(mid) < score) left = mid + 1;
                    else right = mid-1;
                }
                answer[idx++] = map.get(str).size() - left;
            } else answer[idx++] = 0;
        }
        return answer;
    }
    private void dfs(String str, String[] arr, int depth){
        if(depth == 4){
            int score = Integer.parseInt(arr[4]);
            if(map.containsKey(str)) map.get(str).add(score);
            else{
                List<Integer> list = new ArrayList<>();
                list.add(score);
                map.put(str, list);
            }
            return;
        }
        dfs(str+"-", arr, depth+1);
        dfs(str+arr[depth], arr, depth+1);
        
    }
}