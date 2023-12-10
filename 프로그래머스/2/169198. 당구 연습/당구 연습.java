import java.util.ArrayList;
import java.util.List;

class Solution {
    static class Pos {
        int y;
        int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
        int[] answer = new int[balls.length];

        Pos border = new Pos(n, m);
        Pos start = new Pos(startY, startX);

        for (int i = 0; i < balls.length; i++) {
            int[] ball = balls[i];
            List<Pos> symmetricPos = findSymmetricalPoints(border, start, new Pos(ball[1], ball[0]));

            int minDist = Integer.MAX_VALUE;
            for (Pos pos : symmetricPos) {
                minDist = Math.min(calculateDistance(start, pos), minDist);
            }
            answer[i] = minDist;
        }
        return answer;
    }

    /*
    목표 공일 경계에 대칭 시킨 좌표를 구하는 함수
    벽 보다 공을 먼저 치는 경우를 막기 위해 조건문 추가
     */
    private List<Pos> findSymmetricalPoints(Pos border, Pos start, Pos ball) {
        List<Pos> list = new ArrayList<>();

        // 위쪽 경계 대칭
        if (!(start.x == ball.x && start.y < ball.y)) {
            list.add(new Pos(2 * border.y - ball.y, ball.x));
        }

        // 아래쪽 경계 대칭
        if (!(start.x == ball.x && start.y > ball.y)) {
            list.add(new Pos(-1 * ball.y, ball.x));
        }

        // 오른쪽 경계 대칭
        if (!(start.y == ball.y && start.x < ball.x)) {
            list.add(new Pos(ball.y, 2 * border.x - ball.x));
        }

        // 왼쪽 경계 대칭
        if (!(start.y == ball.y && start.x > ball.x)) {
            list.add(new Pos(ball.y, -1 * ball.x));
        }

        return list;
    }

    private int calculateDistance(Pos start, Pos ball) {
        return (int) (Math.pow(ball.y - start.y, 2) + Math.pow(ball.x - start.x, 2));
    }
}