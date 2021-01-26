import java.util.*;
import java.io.*;

public class BOJ_3197 {
    private static final int ROW = 0;
    private static final int COL = 1;
    private static final boolean WATER = true;
    private static final boolean ICE = false;

    private static final int[] dRow = new int[] { -1, 1, 0, 0 };
    private static final int[] dCol = new int[] { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        boolean[][] board = new boolean[R][C];
        int[][] swan = new int[2][2];
        int swanIndex = 0;

        for (int row = 0; row < R; row++) {
            String map = br.readLine();
            for (int col = 0; col < C; col++) {
                if (map.charAt(col) == '.') {
                    board[row][col] = WATER;
                } else if (map.charAt(col) == 'L') {
                    board[row][col] = WATER;
                    swan[swanIndex][ROW] = row;
                    swan[swanIndex][COL] = col;
                    swanIndex++;
                }
            }
        }

        int answer = simulation(R, C, board, swan);
        System.out.println(answer);
    }

    
    private static int simulation(int R, int C, boolean[][] board, int[][] swan) {
        Queue<Pos> posQueue = new LinkedList<>();
        int[][] day = new int[R][C];

        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                day[row][col] = -1;

                if (board[row][col] == WATER) {
                    posQueue.offer(new Pos(row, col));
                    day[row][col] = 0;
                }
            }
        }

        //day에 각 얼음이 몇째 날에 녹는지 저장        
        while (!posQueue.isEmpty()) {
            Pos nowPos = posQueue.peek();
            int nowDay = day[nowPos.row][nowPos.col];
            posQueue.poll();

            for (int direction = 0; direction < 4; direction++) {
                Pos nextPos = new Pos(nowPos.row + dRow[direction], nowPos.col + dCol[direction]);
                if (nextPos.row < 0 || nextPos.row >= R || nextPos.col < 0 || nextPos.col >= C) {
                    continue;
                } else if (day[nextPos.row][nextPos.col] >= 0){
                    continue;
                }
                
                if (board[nextPos.row][nextPos.col] == ICE) {
                    day[nextPos.row][nextPos.col] = nowDay + 1;
                    posQueue.offer(nextPos);
                }
            }
        }

        return findShortWay(R, C, day, swan);
    }

    private static int findShortWay(int R, int C, int[][] day, int[][] swan) {
        int start = 0;
        int target = 1;
        PriorityQueue<Pos> posPriorityQueue = new PriorityQueue<>();
        boolean[][] mask = new boolean[R][C];

        mask[swan[start][ROW]][swan[start][COL]] = true;
        posPriorityQueue.offer(new Pos(swan[start][ROW], swan[start][COL]));

        while(!posPriorityQueue.isEmpty()) {
            Pos nowPos = posPriorityQueue.peek();
            posPriorityQueue.poll();

            if (swan[target][ROW] == nowPos.row && swan[target][COL] == nowPos.col) {
                return nowPos.maxDay;
            }

            for (int direction = 0; direction < 4; direction++) {
                Pos nextPos = new Pos(nowPos.row + dRow[direction], nowPos.col + dCol[direction]);
                if (nextPos.row < 0 || nextPos.row >= R || nextPos.col < 0 || nextPos.col >= C) {
                    continue;
                } else if (mask[nextPos.row][nextPos.col]){
                    continue;
                }

                mask[nextPos.row][nextPos.col] = true;
                nextPos.maxDay = max(nowPos.maxDay, day[nextPos.row][nextPos.col]);
                posPriorityQueue.offer(nextPos);
            }
        }

        return -1;
    }

    private static int max(int a, int b) {
        return a >= b ? a : b;
    }

    private static class Pos implements Comparable<Pos>{
        public int row;
        public int col;
        public int maxDay;

        public Pos(int row, int col) {
            this.row = row;
            this.col = col;
            this.maxDay = -1;
        }

        @Override
        public int compareTo(Pos other) {
            return this.maxDay - other.maxDay;
        }
    }
}