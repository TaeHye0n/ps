import java.util.*;

class Solution {
    static Set<Integer> combSet = new HashSet<>();
    
    public int solution(String numbers) {
        int answer = 0;
        makeComb("", numbers);
        
        for (int number : combSet) {
            if (isPrime(number)) {
                answer++;
            }
        }
        return answer;
    }
    
    private void makeComb(String comb, String others) {
        if (!comb.equals("")) {
            combSet.add(Integer.parseInt(comb));
        }
        
        for (int i = 0; i < others.length(); i++) {
            makeComb(comb + others.charAt(i), others.substring(0, i) + others.substring(i+1));
        }
    }
    
    private boolean isPrime(int number) {
        
        if (number == 0 || number == 1) return false;
        
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) return false;
        }
        
        return true;
    }
}