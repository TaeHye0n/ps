import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int initialAtk;
    static class Dungeon {
        int t;
        int a;
        int h;

        Dungeon (int t, int a, int h) {
            this.t = t;
            this.a = a;
            this.h = h;
        }
    }

    static List<Dungeon> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        initialAtk = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());

            list.add(new Dungeon(t, a, h));
        }
        long left = 0;
        long right = Long.MAX_VALUE - 1;
        while (left <= right) {
            long mid = (left + right) / 2;
            long hp = mid;
            long atk = initialAtk;
            boolean isAlive = true;

            for (int i = 0; i < N; i++) {
                if(list.get(i).t == 1) {
                    if (list.get(i).h % atk == 0) hp -= (list.get(i).h / atk - 1) * list.get(i).a;
                    else hp -= (list.get(i).h / atk) * list.get(i).a;
                    if (hp <= 0) {
                        isAlive = false;
                        break;
                    }
                } else {
                    hp += list.get(i).h;
                    hp = hp > mid ? mid : hp;
                    atk += list.get(i).a;
                }
            }
            if (!isAlive) left = mid + 1;
            else right = mid - 1;
        }
        System.out.println(left);
    }


}