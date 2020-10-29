import java.util.*;
import java.io.*;

public class BOJ_16933 {
    private static final int[] dY = new int[]{0 ,1 ,0, -1};
    private static final int[] dX = new int[]{1 ,0 ,-1, 0};
    private static final int INF = 4000001;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

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

        Queue<Pos> q = new LinkedList<Pos>();
        q.offer(new Pos(0, 0, 0));
        mask[0][0][0] = 1;

        while(!q.isEmpty())
        {
            int y = q.peek().y;
            int x = q.peek().x;
            int k = q.peek().k;
            boolean wait = false;
            q.poll();

            for(int direction = 0; direction < 4; direction++)
            {
                int nextY = y + dY[direction];
                int nextX = x + dX[direction];
                if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                    continue;
                
                if(board[nextY][nextX] == 0 && mask[nextY][nextX][k] == 0)
                {
                    mask[nextY][nextX][k] = mask[y][x][k] + 1;
                    q.offer(new Pos(nextY, nextX, k));
                }
                if(board[nextY][nextX] == 1)
                {
                    if(k == K || mask[nextY][nextX][k + 1] > 0)
                        continue;
                    if((mask[y][x][k] + 1) % 2 == 0)//낮
                    {
                        mask[nextY][nextX][k + 1] = mask[y][x][k] + 1;
                        q.offer(new Pos(nextY, nextX, k + 1));
                    }
                    else//밤
                    {
                        wait = true;
                    }
                }
            }
            if(wait)
            {
                mask[y][x][k]++;
                q.offer(new Pos(y, x, k));
            }
        }

        int answer = INF;
        for(int index = 0; index <= K; index++)
        {
            if(mask[N - 1][M - 1][index] != 0)
            {
                answer = min(answer, mask[N - 1][M - 1][index]);
            }
        }
        if(answer == INF)
            answer = -1;

        System.out.println(answer);
        return;
    }
    private static int min(int a, int b)
    {
        return a < b ? a : b;
    }

    private static class Pos
    {
        public int y;
        public int x;
        public int k;
        public Pos(int y, int x, int k)
        {
            this.y = y;
            this.x = x;
            this.k = k;
        }
    }
}