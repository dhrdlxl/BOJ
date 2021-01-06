import java.util.*;
import java.io.*;

public class BOJ_20056 {
    private static final int[] dR = new int[] { -1, -1, 0, 1, 1, 1, 0, -1 };
    private static final int[] dC = new int[] { 0, 1, 1, 1, 0, -1, -1, -1 };
    private static final int[][] newDirection = new int[][] { { 0, 2, 4, 6 }, { 1, 3, 5, 7 } };
    private static final int EVEN = 0;
    private static final int ODD = 1;

    private static ArrayList<FireBall>[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());// 격자 크기
        int fireBallCount = Integer.parseInt(st.nextToken());// 파이어볼 개수
        int K = Integer.parseInt(st.nextToken());// 이동 횟수
        int sumOfMass = 0;

        board = new ArrayList[N + 1][N + 1];

        for (int row = 1; row <= N; row++) {
            for (int col = 1; col <= N; col++) {
                board[row][col] = new ArrayList<>();
            }
        }

        for (int index = 0; index < fireBallCount; index++) {
            st = new StringTokenizer(br.readLine());

            int row = Integer.parseInt(st.nextToken());
            int col = Integer.parseInt(st.nextToken());
            int mass = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());
            int direction = Integer.parseInt(st.nextToken());

            board[row][col].add(new FireBall(mass, speed, direction));
            sumOfMass += mass;
        }

        int answer = simulation(N, K, sumOfMass);

        System.out.println(answer);
    }

    private static int simulation(int N, int K, int sumOfMass) {
        for (int step = 1; step <= K; step++) {
            move(N, step);

            sumOfMass += combineAndDivide(N, step);
        }

        return sumOfMass;
    }

    private static ArrayList<FireBall> makeNewFireBall(int evenOrOdd, int mass, int speed, int step) {
        ArrayList<FireBall> result = new ArrayList<>();

        for (int direction : newDirection[evenOrOdd]) {
            result.add(new FireBall(mass, speed, direction, step));
        }

        return result;
    }

    private static int combineAndDivide(int N, int step) {
        int changedMass = 0;

        for (int row = 1; row <= N; row++) {
            for (int col = 1; col <= N; col++) {
                if (board[row][col].size() > 1) {
                    int mass = 0;
                    int speed = 0;
                    int direction = 0;
                    int combineFireBallCount = board[row][col].size();

                    for (FireBall fireBall : board[row][col]) {
                        mass += fireBall.mass;
                        speed += fireBall.speed;
                        direction += (fireBall.direction % 2);

                        changedMass -= fireBall.mass;
                    }

                    mass /= 5;
                    speed /= combineFireBallCount;

                    board[row][col].clear();

                    if (mass > 0) {
                        if (direction == 0 || direction == combineFireBallCount) {
                            board[row][col].addAll(makeNewFireBall(EVEN, mass, speed, step));
                        } else {
                            board[row][col].addAll(makeNewFireBall(ODD, mass, speed, step));
                        }

                        for (FireBall fireBall : board[row][col]) {
                            changedMass += fireBall.mass;
                        }
                    }

                }
            }
        }
        return changedMass;
    }

    private static void move(int N, int step) {
        for (int row = 1; row <= N; row++) {
            for (int col = 1; col <= N; col++) {
                for (int index = board[row][col].size() - 1; index >= 0; index--) {
                    FireBall fireBall = board[row][col].get(index);
                    if (fireBall.step < step) {
                        int nextRow = row + (dR[fireBall.direction] * fireBall.speed);
                        int nextCol = col + (dC[fireBall.direction] * fireBall.speed);
                        nextRow = ((nextRow - 1) % N + N) % N + 1;
                        nextCol = ((nextCol - 1) % N + N) % N + 1;

                        fireBall.step = step;
                        board[nextRow][nextCol].add(fireBall);
                        board[row][col].remove(index);
                    }
                }
            }
        }
    }

    private static class FireBall {
        public int mass;
        public int speed;
        public int direction;
        public int step = 0;

        public FireBall(int mass, int speed, int direction, int step) {
            this.mass = mass;
            this.speed = speed;
            this.direction = direction;
            this.step = step;
        }

        public FireBall(int mass, int speed, int direction) {
            this.mass = mass;
            this.speed = speed;
            this.direction = direction;
        }
    }
}