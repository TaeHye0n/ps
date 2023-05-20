import java.util.*;
import java.io.*;

class Solution {
    public long[] solution(long[] numbers) {
        List<Long> result = new ArrayList<>();
        
        for(int i = 0; i < numbers.length; i++){
            long num = numbers[i];
            if(num % 2 == 0) result.add(num+1);
            else{
                long temp = num;
                long idx = 0;
                while(true){
                    long mod = temp%2;
                    idx++;
                    if(mod == 0) break;
                    temp /= 2;
                }
                long plus = (long)Math.pow(2,idx-1);
                long minus = (long)Math.pow(2,idx-2);
                result.add(num+plus-minus);
            }
        }
        return result.stream().mapToLong(i->i).toArray();
    }
}