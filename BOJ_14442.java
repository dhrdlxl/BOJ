import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_14442 {
    private static final int[] dY = new int[]{0, -1, 0, 1};
    private static final int[] dX = new int[]{-1, 0, 1, 0};
    private static int N;
    private static int M;
    private static int K;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int[][] board = new int[N][M];
        int[][][] mask = new int[N][M][K + 1];
        for(int row = 0; row < N; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < M; col++)
            {
                board[row][col] = (int)(line.charAt(col) - '0');
            }
        }

        bfs(board, mask);

        int answer = 2000001;
        for(int index = 0; index <= K; index++)
        {
            if(mask[N - 1][M - 1][index] > 0)
                answer = min(answer, mask[N - 1][M - 1][index]);
        }

        if(answer == 2000001)
            answer = -1;
        System.out.println(answer);

        return;
    }
    private static void bfs(int[][] board, int[][][] mask)
    {
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        q.offer(0);
        q.offer(0);
        mask[0][0][0] = 1;

        while(!q.isEmpty())
        {
            int y = q.poll();
            int x = q.poll();
            int k = q.poll();
            for(int direction = 0; direction < 4; direction++)
            {
                int nextY = y + dY[direction];
                int nextX = x + dX[direction];
                if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                    continue;
                
                if(board[nextY][nextX] == 0)
                {
                    if(mask[nextY][nextX][k] == 0)
                    {
                        mask[nextY][nextX][k] = mask[y][x][k] + 1;
                        q.offer(nextY);
                        q.offer(nextX);
                        q.offer(k);
                    }
                }
                else if(board[nextY][nextX] == 1)
                {
                    if(k == K)
                        continue;
                    if(mask[nextY][nextX][k + 1] == 0)
                    {
                        mask[nextY][nextX][k + 1] = mask[y][x][k] + 1;
                        q.offer(nextY);
                        q.offer(nextX);
                        q.offer(k + 1);
                    }
                }
            }
        }

        return;
    }

    private static int min(int a, int b)
    {
        return a < b ? a : b;
    }

}
