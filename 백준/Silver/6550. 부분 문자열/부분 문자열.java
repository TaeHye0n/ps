import java.util.*;
import java.io.*;

public class Main{
    static String str;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while(true){
            str = br.readLine();
            if(str == null) break;

            StringTokenizer st = new StringTokenizer(str);
            String s = st.nextToken();
            String t = st.nextToken();

            int idx = 0;
            boolean flag = false;
            for(int i = 0; i < t.length(); i++){
                if(s.charAt(idx) == t.charAt(i)) idx++;

                if(idx == s.length()){
                    flag = true;
                    break;
                }
            }
            if(flag) sb.append("Yes\n");
            else sb.append("No\n");
        }
        System.out.println(sb.toString());
    }
}

