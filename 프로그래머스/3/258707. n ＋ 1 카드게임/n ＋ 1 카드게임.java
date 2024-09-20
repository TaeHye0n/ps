import java.util.*;
import java.io.*;

class Solution {
    
    static Set<Integer> hands = new HashSet<>();
    static Set<Integer> picks = new HashSet<>();
    static Queue<Integer> decks = new ArrayDeque<>();
    static int target = 0;
    
    public int solution(int coin, int[] cards) {
        int answer = 1;
        int n = cards.length;
        target = n + 1;
        for (int i = 0; i < n / 3; i++) {
            hands.add(cards[i]);
        }
        
        for (int i = n / 3; i < n; i++) {
            decks.add(cards[i]);
        }
        
        while (coin >= 0 && decks.size() > 0) {
            picks.add(decks.poll());
            picks.add(decks.poll());
            if (isPossible(hands, hands)){
                
            }
            else if (coin >= 1 && isPossible(hands, picks)) {
                coin--;
            }
            else if (coin >= 2 && isPossible(picks, picks)) {
                coin -= 2;
            } 
            else break;
            
            answer++;
        }
        return answer;
    }
    
    static boolean isPossible(Set<Integer> ASet, Set<Integer> BSet) {
        for (Integer card : ASet) {
            int another_card = target - card;
            if (BSet.contains(another_card)) {
                ASet.remove(card);
                BSet.remove(another_card);
                return true;
            }
        }
        return false;
    }
}