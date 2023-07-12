import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int[][] city = new int[V+1][V+1];

        for (int i = 1; i <= V; i++) {
            Arrays.fill(city[i] , Integer.MAX_VALUE / 2);
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            city[from][to] = cost;
        }

        for (int k = 1; k <=V; k++) {
            for (int i = 1; i <= V; i++) {
                for (int j = 1; j <= V; j++) {
                    city[i][j] = Math.min(city[i][j], city[i][k] + city[k][j]);
                }
            }
        }

        int answer = Integer.MAX_VALUE / 2;

        for (int i = 1; i <= V; i++) {
            answer = Math.min(answer, city[i][i]);
        }
        answer = (answer == Integer.MAX_VALUE / 2) ? -1 : answer;
        System.out.println(answer);
    }
}