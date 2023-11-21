class Solution {
    public int[] solution(int brown, int yellow) {   
        int[] answer = new int[2];
        
        int colorSum = brown + yellow;
        
        for (int height = 3; height < colorSum; height++) {
            if (colorSum % height == 0) {
                int width = colorSum / height;
                int expectedYellow = (width - 2) * (height - 2);
                if (expectedYellow == yellow) {
                    answer[0] = width;
                    answer[1] = height;
                    break;
                }
            }
        }
        return answer;
    }
}