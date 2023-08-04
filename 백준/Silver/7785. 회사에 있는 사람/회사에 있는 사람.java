import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, String> map = new HashMap<>();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String who = st.nextToken();
            String what = st.nextToken();

            if (what.equals("leave") && map.containsKey(who)) {
                map.remove(who);
            } else if (what.equals("enter")) {
                map.put(who, what);
            }
        }
        map.keySet().stream().sorted(Collections.reverseOrder()).forEach(s -> sb.append(s).append("\n"));
        System.out.println(sb);
    }
}