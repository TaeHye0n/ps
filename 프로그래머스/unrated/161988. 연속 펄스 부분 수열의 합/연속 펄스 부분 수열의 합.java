class Solution {
    static int[] arr1, arr2;
    static long[] dp1, dp2;
    
    public long solution(int[] sequence) {
        long answer = 0;
        int len = sequence.length;
        arr1 = new int[len];
        arr2 = new int[len];
        
        int multi = 1;
        for (int i = 0; i < len; i++) {
            arr1[i] = sequence[i] * multi;
            multi *= -1;
            arr2[i] = sequence[i] * multi;
        }
        
        dp1 = new long[len];
        dp2 = new long[len];
        
        dp1[0] = arr1[0];
        dp2[0] = arr2[0];
        answer = Math.max(dp1[0], dp2[0]);
        
        for (int i = 1; i < len; i++) {
            dp1[i] = Math.max(dp1[i-1] + arr1[i], arr1[i]);
            dp2[i] = Math.max(dp2[i-1] + arr2[i], arr2[i]);
            
            long max = Math.max(dp1[i], dp2[i]);
            answer = Math.max(answer, max);
        }
        return answer;
    }
}