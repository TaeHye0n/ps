import java.util.*;
import java.io.*;

class Solution {
    static String[][] relation;
    static Set<String> set = new HashSet<>();
    static int[] arr;
    
    public int solution(String[][] relation) {
        this.relation = relation;
        int answer = 0;
        arr = new int[relation[0].length + 1];
        for (int i = 1; i <= relation[0].length; i++) {
            func(0, 0, i);
        }
        
        // set.stream().forEach(System.out::println);
        return set.size();
    }
    
    private static void func(int idx, int depth, int bound) {
        if (depth == bound) {
            String comb = "";
            int cnt = 0;
            for (int i = 0; i < relation[0].length; i++) {
                if (cnt == bound) break;
                comb += arr[i];
                cnt++;
            }
            // System.out.println(comb);
            if (check(comb)) {
                set.add(comb);
            }
            return;
        }
        
        for (int i = idx; i < relation[0].length; i++) {
            arr[depth] = i;
            func(i + 1, depth + 1, bound);
        }
    }
    
    private static boolean check(String comb) {
        // for (String s : set) {
        //     for (int i = 0; i < s.length(); i++) {
        //         if (comb.contains(Character.toString(s.charAt(i)))) return false;
        //     }
        // }
        
        for (String s : set) {
            boolean flag = true; 
            for (int i = 0; i < s.length(); i++) {
                if(!comb.contains(s.charAt(i)+"")){
                    flag = false;
                }
            }

            if(flag){ 
                return false;
            }
        }
        
        Set<String> rowSet = new HashSet<>();
        // System.out.println(comb);
        for (int i = 0; i < relation.length; i++) {
            String str = "";
            for (int j = 0; j < comb.length(); j++) {
                str += relation[i][comb.charAt(j) - '0'];
            }
            // System.out.println(str);
            rowSet.add(str);
        }
        if (rowSet.size() != relation.length) return false;
        return true;
    }
}