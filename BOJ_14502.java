import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_14502 {
    private static final int[] dY = new int[]{1, 0, -1, 0};
    private static final int[] dX = new int[]{0, 1, 0, -1};
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] board = new int[N][M];
        int zeroCount = 0;
        for(int row = 0; row < N; row++)
        {
            st = new StringTokenizer(br.readLine());
            for(int col = 0; col < M; col++)
            {
                board[row][col] = Integer.parseInt(st.nextToken());
                if(board[row][col] == 0)
                {
                    zeroCount++;
                }
            }
        }
        zeroCount -= 3;//new Wall

        int answer = 0;
        for(int wall1 = 0; wall1 < N * M; wall1++)
        {
            int wall1Y = wall1 / M;
            int wall1X = wall1 % M;
            if(board[wall1Y][wall1X] != 0)
                continue;
            for(int wall2 = wall1 + 1; wall2 < N * M; wall2++)
            {
                int wall2Y = wall2 / M;
                int wall2X = wall2 % M;
                if(board[wall2Y][wall2X] != 0)
                    continue;
                for(int wall3 = wall2 + 1; wall3 < N * M; wall3++)
                {
                    int wall3Y = wall3 / M;
                    int wall3X = wall3 % M;
                    if(board[wall3Y][wall3X] != 0)
                        continue;

                    board[wall1Y][wall1X] = 1;
                    board[wall2Y][wall2X] = 1;
                    board[wall3Y][wall3X] = 1;

                    answer = max(answer ,bfs(board, zeroCount));

                    board[wall1Y][wall1X] = 0;
                    board[wall2Y][wall2X] = 0;
                    board[wall3Y][wall3X] = 0;
                }
            }
        }

        System.out.println(answer);
        return;
    }
    private static int bfs(int[][] board, int zeroCount)
    {
        Queue<Integer> q = new LinkedList<>();
        int N = board.length;
        int M = board[0].length;
        boolean[][] mask = new boolean[N][M];

        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < M; col++)
            {
                if(board[row][col] == 2)
                {
                    q.offer(row);
                    q.offer(col);
                    mask[row][col] = true;
                }
            }
        }

        int virusCount = 0;

        while(!q.isEmpty())
        {
            int y = q.poll();
            int x = q.poll();

            for(int direction = 0; direction < 4; direction++)
            {
                int nextY = y + dY[direction];
                int nextX = x + dX[direction];
                if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                    continue;
                if(board[nextY][nextX] == 0 && mask[nextY][nextX] == false)
                {
                    virusCount++;
                    mask[nextY][nextX] = true;
                    q.offer(nextY);
                    q.offer(nextX);
                }
            }
        }

        return zeroCount - virusCount;
    }

    private static int max(int a, int b)
    {
        return a > b? a : b;
    }
}
