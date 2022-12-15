import java.util.*;
import java.io.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        HashMap<String, Integer> hm = new HashMap<>();
        
        for(String num : phone_book){
            hm.put(num, 1);
        }
        
        for(int i = 0; i < phone_book.length; i++){
            for(int j = 0; j < phone_book[i].length(); j++){
                String temp = phone_book[i].substring(0,j);
                if(hm.containsKey(temp)){
                    answer = false;
                    break;
                }
            }
        }
        
        return answer;
    }
}