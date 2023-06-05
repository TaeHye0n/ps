import java.util.*;
import java.io.*;

public class Main {
    static final int[] dy = {1, -1, 0, 0};
    static final int[] dx = {0, 0, 1, -1};
    static String[][] map;
    static int answer;
    static Set<String> set = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        answer = 0;
        map = new String[5][5];

        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                map[i][j] = st.nextToken();
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                dfs(i, j, 1, map[i][j]);
            }
        }
        System.out.println(set.size());
    }

    private static void dfs(int y, int x, int cnt, String str) {
        if (cnt == 6) {
            set.add(str);
            return;
        }

        for (int w = 0; w < 4; w++) {
            int ny = y + dy[w];
            int nx = x + dx[w];

            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
            dfs(ny, nx, cnt +1, str+map[ny][nx]);
        }
    }
}
