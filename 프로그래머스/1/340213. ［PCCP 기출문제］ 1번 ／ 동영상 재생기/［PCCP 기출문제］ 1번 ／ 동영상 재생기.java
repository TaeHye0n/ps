import java.util.*;
import java.io.*;


class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        int video_len_sec = stringToSec(video_len);
        int pos_sec = stringToSec(pos);
        int op_start_sec = stringToSec(op_start);
        int op_end_sec = stringToSec(op_end);
        
        for (String c : commands) {
            if (op_start_sec <= pos_sec && pos_sec <= op_end_sec) pos_sec = op_end_sec;

            if (c.equals("next")) {
                pos_sec += 10;
                if (pos_sec > video_len_sec) pos_sec = video_len_sec;
            } else if (c.equals("prev")) {
                pos_sec -= 10;
                if (pos_sec < 0) pos_sec = 0;
            }
            
            if (op_start_sec <= pos_sec && pos_sec <= op_end_sec) pos_sec = op_end_sec; 
        }
        answer = secToString(pos_sec);
        return answer;
    }
    
    static int stringToSec(String s) {
        String min = s.substring(0, 2);
        String sec = s.substring(3);
        return Integer.parseInt(min) * 60 + Integer.parseInt(sec);
    }
    
    static String secToString(int sec) {
        StringBuilder sb = new StringBuilder();
        String m = Integer.toString(sec/60);
        String s = Integer.toString(sec%60);
        
        if (m.equals("0")) {
            sb.append("00");
        } else if(m.length() == 1) {
            sb.append("0").append(m);
        } else {
            sb.append(m);
        }
        
        sb.append(":");
        
        if (s.equals("0")) {
            sb.append("00");
        } else if (s.length() == 1) {
            sb.append("0").append(s);
        } else {
            sb.append(s);
        }
        
        return sb.toString();
    }
}