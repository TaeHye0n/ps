class Solution {
    static final char MAX_DIGIT = '9';
    
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder(number);
        
        int idx = -1;
        for (int i = 0; i < sb.length() - 1 && k > 0; i++) {
            if (sb.charAt(i) == MAX_DIGIT) {
                idx = i;
            }
            if (sb.charAt(i) < sb.charAt(i + 1)) {
                sb.deleteCharAt(i);
                i = idx;
                k--;
            }
        }
        
        if (k != 0) {
            sb.delete(sb.length() - k, sb.length());
        }
        return sb.toString();
    }
}