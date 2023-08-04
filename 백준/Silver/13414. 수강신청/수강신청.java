import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < L; i++) {
            String str = br.readLine();
            map.put(str, i);
        }

        List<String> collect = map.keySet().stream().sorted(Comparator.comparing(map::get)).collect(Collectors.toList());
        for (int i = 0; i < collect.size(); i++) {
            sb.append(collect.get(i)).append("\n");
            K--;
            if (K == 0) break;
        }
        System.out.println(sb);
    }
}