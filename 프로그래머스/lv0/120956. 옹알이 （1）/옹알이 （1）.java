import java.util.*;
import java.io.*;

class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        for(String str : babbling){
            str = str.replaceFirst("aya", "-");
            str = str.replaceFirst("ye", "-");
            str = str.replaceFirst("woo", "-");
            str = str.replaceFirst("ma", "-");
            
            str = str.replace("-","");
            
            if(str.equals("")) answer++;
        }
        return answer;
    }
}