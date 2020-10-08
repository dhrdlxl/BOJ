import java.io.*;
import java.util.*;

public class BOJ_16929 {
    private static int[] dY = {-1, 0, 1, 0};
    private static int[] dX = {0, 1, 0, -1};

    private static final int NOT_VISIT = -1;
    private static final int START = 0;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        char[][] board = new char[N][M];
        int[][] mask = new int[N][M];

        for(int row = 0; row < N; row++)
        {
            String s = br.readLine();
            for(int col = 0; col < M; col++)
            {
                board[row][col] = s.charAt(col);
                mask[row][col] = -1;
            }
        }

        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < M; col++)
            {
                if(mask[row][col] == NOT_VISIT)
                {
                    if(bfs(board, mask, new Pos(row, col)))
                    {
                        System.out.println("Yes");
                        return;
                    }
                }
            }
        }
        
        System.out.println("No");
        return;
    }    
    private static boolean bfs(char[][] board, int[][] mask, Pos start)
    {
        Queue<Pos> q = new LinkedList<>();
        q.offer(new Pos(start.y, start.x));
        mask[start.y][start.x] = START;

        int N = board.length;
        int M = board[0].length;

        while(!q.isEmpty())
        {
            Pos now = q.poll();
            int nowY = now.y;
            int nowX = now.x;
            int visitNumber = mask[nowY][nowX] + 1;

            for(int direction = 0; direction < 4; direction++)
            {
                int nextY = nowY + dY[direction];
                int nextX = nowX + dX[direction];

                if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) 
                    continue;
                
                if(board[nowY][nowX] == board[nextY][nextX])
                {
                    if(mask[nextY][nextX] == NOT_VISIT)
                    {
                        mask[nextY][nextX] = visitNumber;
                        q.offer(new Pos(nextY, nextX));
                    }
                    else if(mask[nextY][nextX] == visitNumber){//already visit
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private static class Pos
    {
        public int y;
        public int x;
        Pos(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}
