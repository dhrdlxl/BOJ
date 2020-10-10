import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1780 {
    private static final int[] dY = new int[] { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
    private static final int[] dX = new int[] { 0, 1, 2, 0, 1, 2, 0, 1, 2 };

    private static int[][] board;
    private static int[] answer = new int[3];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        StringTokenizer st;
        for (int row = 0; row < N; row++) {
            st = new StringTokenizer(br.readLine());
            for (int col = 0; col < N; col++) {
                board[row][col] = Integer.parseInt(st.nextToken());
            }
        }

        compress(0, 0, N);

        for (int index = 0; index < 3; index++)
            System.out.println(answer[index]);

        return;
    }

    private static void compress(int startY, int startX, int length) {
        if (isAllSame(startY, startX, length))
            return;

        int nextLength = length / 3;
        for (int index = 0; index < 9; index++) {
            int nextY = startY + nextLength * dY[index];
            int nextX = startX + nextLength * dX[index];

            compress(nextY, nextX, nextLength);
        }
    }

    private static boolean isAllSame(int y, int x, int length) {
        int checkSum = board[y][x];

        for (int row = y; row < y + length; row++) {
            for (int col = x; col < x + length; col++) {
                if (board[row][col] != checkSum) {
                    return false;
                }
            }
        }

        answer[checkSum + 1]++;
        return true;
    }
}
