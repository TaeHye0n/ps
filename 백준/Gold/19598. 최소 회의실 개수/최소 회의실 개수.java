import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int answer = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = null;
        PriorityQueue<Room> pq = new PriorityQueue<>();
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            Room room = new Room(start,end);
            pq.offer(room);
        }
        PriorityQueue<Integer> using = new PriorityQueue<>();

        while(!pq.isEmpty()){
            Room room = pq.poll();
            if(using.isEmpty()) using.offer(room.ed);
            else{
                if(using.peek() <= room.start){
                    using.remove();
                    using.offer(room.ed);
                }
                else using.offer(room.ed);
            }
            answer = Math.max(answer, using.size());
        }
        System.out.println(answer);
    }

    static class Room implements Comparable<Room>{
        int start,ed;

        public Room(int start, int ed) {
            this.start = start;
            this.ed = ed;
        }

        @Override
        public int compareTo(Room o) {
            if(this.start == o.start) return this.ed - o.ed;
            return this.start - o.start;
        }
    }
}