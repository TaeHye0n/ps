import java.util.*;
import java.io.*;

public class Main {
    static int N; // 강의의 개수
    static PriorityQueue<Integer> pq = new PriorityQueue<>();
    static List<Lecture> list = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        N = stoi(br.readLine());

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int num = stoi(st.nextToken());
            int start = stoi(st.nextToken());
            int end = stoi(st.nextToken());
            list.add(new Lecture(num, start, end));
        }
        Collections.sort(list);

        int answer = 1;
        for(int i = 0; i < N; i++){
            while(!pq.isEmpty() && pq.peek() <= list.get(i).startTime){
                pq.poll();
            }
            pq.offer(list.get(i).endTime);
            answer = Math.max(answer, pq.size());
        }
        System.out.println(answer);
    }
    private static int stoi(String s){
        return Integer.parseInt(s);
    }

    static class Lecture implements Comparable<Lecture>{
        int num;
        int startTime;
        int endTime;

        Lecture(int num, int startTime, int endTime){
            this.num = num;
            this.startTime = startTime;
            this.endTime = endTime;
        }

        @Override
        public int compareTo(Lecture o){
            if(this.startTime == o.startTime) return this.endTime - o.endTime;
            return this.startTime - o.startTime;
        }
    }
}