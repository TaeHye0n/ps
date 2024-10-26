import java.util.*;
import java.io.*;

public class Main {

    static int n;
    static int mp;
    static int mf;
    static int ms;
    static int mv;
    static List<Food> foods = new ArrayList<>();
    static int answer;
    static List<Integer> answerList = new ArrayList<>();
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = stoi(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        mp = stoi(st.nextToken());
        mf = stoi(st.nextToken());
        ms = stoi(st.nextToken());
        mv = stoi(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int p = stoi(st.nextToken());
            int f = stoi(st.nextToken());
            int s = stoi(st.nextToken());
            int v = stoi(st.nextToken());
            int c = stoi(st.nextToken());
            foods.add(new Food(p, f, s, v, c));
        }
        answer = Integer.MAX_VALUE;
        dfs(0, 0, 0, 0, 0, 0,  new ArrayList<>());
        if (answer == Integer.MAX_VALUE) {
            System.out.println(-1);
            return;
        }
        System.out.println(answer);
        answerList.forEach(it -> System.out.print(it +" "));
    }

    static void dfs(int idx, int pSum, int fSum, int sSum, int vSum, int cSum, List<Integer> saved) {
        if (pSum >= mp && fSum >= mf && sSum >= ms && vSum >= mv) {
            if (answer > cSum) {
                answer = cSum;
                answerList.clear();
                answerList.addAll(saved);
                return;
            }
        }

        if (idx >= n) return;

        for (int i = idx; i < n; i++) {
            saved.add(i + 1);
            dfs(i + 1, pSum + foods.get(i).p, fSum + foods.get(i).f,
                    sSum + foods.get(i).s, vSum + foods.get(i).v, cSum + foods.get(i).c, saved);
            saved.remove(saved.size() - 1);
        }
    }

    static class Food {
        int p, f, s, v, c;

        public Food(int p, int f, int s, int v, int c) {
            this.p = p;
            this.f = f;
            this.s = s;
            this.v = v;
            this.c = c;
        }
    }
    static int stoi(String s) {
        return Integer.parseInt(s);
    }

}
