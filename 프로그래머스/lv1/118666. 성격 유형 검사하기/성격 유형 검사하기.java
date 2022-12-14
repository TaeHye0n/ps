import java.util.*;
import java.io.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        HashMap<Character, Integer> hm = new HashMap<>();
        hm.put('R',0);hm.put('T',0);
        hm.put('C',0);hm.put('F',0);
        hm.put('J',0);hm.put('M',0);
        hm.put('A',0);hm.put('N',0);
        
        for(int i = 0; i < survey.length; i++){
            if(choices[i] == 1) hm.put(survey[i].charAt(0), hm.get(survey[i].charAt(0))+3);
            else if(choices[i] == 2) hm.put(survey[i].charAt(0),hm.get(survey[i].charAt(0))+2);
            else if(choices[i] == 3) hm.put(survey[i].charAt(0),hm.get(survey[i].charAt(0))+1);
            else if(choices[i] == 5) hm.put(survey[i].charAt(1),hm.get(survey[i].charAt(1))+1);
            else if(choices[i] == 6) hm.put(survey[i].charAt(1),hm.get(survey[i].charAt(1))+2);
            else if(choices[i] == 7) hm.put(survey[i].charAt(1),hm.get(survey[i].charAt(1))+3);
            else continue;
        }
        
        if(hm.get('R') >= hm.get('T')) answer += 'R';
        else answer += 'T';
        if(hm.get('C') >= hm.get('F')) answer += 'C';
        else answer += 'F';
        if(hm.get('J') >= hm.get('M')) answer += 'J';
        else answer += 'M';
        if(hm.get('A') >= hm.get('N')) answer += 'A';
        else answer += 'N';
        return answer;
    }
}