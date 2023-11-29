import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;


public class Solution {
    static Map<String, Integer> combs;
    static int maxCount;

    public String[] solution(String[] orders, int[] course) {
        PriorityQueue<String> pq = new PriorityQueue<>();

        for (int i = 0; i < orders.length; i++) {
            char[] charArray = orders[i].toCharArray();
            Arrays.sort(charArray);
            orders[i] = String.valueOf(charArray);            
        }

        for (int i = 0; i < course.length; i++) {
            combs = new HashMap<>();
            maxCount = 0;
            for (int j = 0; j < orders.length; j++) {
                if (orders[j].length() < course[i]) continue;
                StringBuilder sb = new StringBuilder();
                comb(orders[j], sb, 0, 0, course[i]);
            }

            for (String str : combs.keySet()) {
                if (combs.get(str) == maxCount && maxCount >= 2) {
                    pq.offer(str);
                }
            }
        }
        String[] answer = new String[pq.size()];
        
        int idx = 0;
        while (!pq.isEmpty()) {
            answer[idx++] = pq.poll();
        }
        
        return answer;
    }

    private void comb(String order, StringBuilder sb, int idx, int cnt, int course) {
        if (cnt == course) {
            combs.put(sb.toString(), combs.getOrDefault(sb.toString(), 0) + 1);
            maxCount = Math.max(maxCount, combs.get(sb.toString()));
            return;
        }

        for (int i = idx; i < order.length(); i++) {
            sb.append(order.charAt(i));
            comb(order, sb, i + 1, cnt + 1, course);
            sb.delete(cnt, cnt + 1);
        }
    }
}
