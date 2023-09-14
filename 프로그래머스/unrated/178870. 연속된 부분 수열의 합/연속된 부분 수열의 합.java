
class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[]{0, 0};
        int ed = 0;
        int len = Integer.MAX_VALUE;
        int n = sequence.length;
        int sum = sequence[0];

        for (int st = 0; st < n; st++) {
            while (ed < n && sum < k) {
                ed++;
                if (ed != n) sum += sequence[ed];
            }
            if (ed == n) break;
            if (sum == k) {
                if (ed - st < len) {
                    len = ed - st;
                    answer[0] = st;
                    answer[1] = ed;
                } else if ((ed - st == len) && st < answer[0]) {
                    answer[0] = st;
                    answer[1] = ed;
                }
            }
            sum -= sequence[st];
        }
        return answer;
    }
}