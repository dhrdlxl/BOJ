import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

public class BOJ_7562 {
    private static final int[] dY = new int[] { -2, -1, 1, 2, 2, 1, -1, -2 };
    private static final int[] dX = new int[] { 1, 2, 2, 1, -1, -2, -2, -1 };
    private static final int NOT_VISIT = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int testCase = Integer.parseInt(br.readLine());

        for (int test = 0; test < testCase; test++) {
            int N = Integer.parseInt(br.readLine());
            int[][] board = new int[N][N];

            StringTokenizer st = new StringTokenizer(br.readLine());
            Pos start = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

            st = new StringTokenizer(br.readLine());
            Pos end = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

            simulation(start, end, board);

            bw.write(Integer.toString(board[end.y][end.x]) + "\n");
        }
        bw.flush();
        bw.close();
        return;
    }

    private static void simulation(Pos start, Pos end, int[][] board) {
        if (start.y == end.y && start.x == end.x)
            return;
        
        int N = board.length;
        Queue<Pos> q = new LinkedList<>();
        q.offer(start);

        while (!q.isEmpty()) {
            Pos now = q.poll();
            int y = now.y;
            int x = now.x;

            for (int index = 0; index < dY.length; index++) {
                int nextY = y + dY[index];
                int nextX = x + dX[index];

                if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
                    continue;

                if (board[nextY][nextX] == NOT_VISIT) {
                    board[nextY][nextX] = board[y][x] + 1;

                    if (nextY == end.y && nextX == end.x)
                        return;

                    q.offer(new Pos(nextY, nextX));
                }
            }
        }

        return;
    }

    private static class Pos {
        public int y;
        public int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
