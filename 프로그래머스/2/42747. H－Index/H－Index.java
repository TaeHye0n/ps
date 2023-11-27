import java.util.Arrays;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        
        
        for (int i = 0; i < citations.length; i++) {
            int count = citations.length - i;
            
            if (citations[i] >= count) {
                answer = count;
                break;
            }
        }
        return answer;
    }
}