import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Long S = Long.parseLong(br.readLine());
        Long sum = 0L;
        int start = 1;
        int cnt = 0;
        while(true){
            sum += (start++);
            if(sum > S) break;
            cnt++;
        }
        System.out.println(cnt);
    }
}