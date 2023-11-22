class Solution {
    static int answer;
    
    public int solution(int[] numbers, int target) {
        answer = 0;
        
        dfs(numbers, target, -numbers[0], 0);
        dfs(numbers, target, numbers[0], 0);
        return answer;
    }
    
    private void dfs(int[] numbers, int target, int sum, int depth) {
        if (depth == numbers.length - 1) {
            if (sum == target) {
                answer++;
            }
            return;
        }
        
        dfs(numbers, target, sum - numbers[depth + 1], depth + 1);
        dfs(numbers, target, sum + numbers[depth + 1], depth + 1);
    }
}