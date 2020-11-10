import java.util.*;
import java.io.*;

public class BOJ_6087 {
    private static final int[] dY = new int[]{-1, 0, 1, 0};
    private static final int[] dX = new int[]{0, -1, 0, 1};
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int W = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());
        char[][] board = new char[H][W];

        Pos startPos = null;
        Pos endPos = null;

        for(int row = 0; row < H; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < W; col++)
            {
                board[row][col] = line.charAt(col);
                if(board[row][col] == 'C')
                {
                    if(startPos == null)
                    {
                        startPos = new Pos(row, col);
                    }
                    else
                    {
                        endPos = new Pos(row, col);
                    }
                }
            }
        }

        int answer = bfs(startPos, board, endPos);

        System.out.println(answer);
        return;
    }
    private static int bfs(Pos startPos, char[][] board, Pos endPos)
    {
        int H = board.length;
        int W = board[0].length;

        Queue<Pos> q = new LinkedList<>();
        int[][] mask = new int[H][W];
        for(int row = 0; row < H; row++)
        {
            for(int col = 0; col < W; col++)
            {
                mask[row][col] = -1;
            }
        }
        mask[startPos.y][startPos.x] = 0;
        q.offer(startPos);

        while(!q.isEmpty())
        {
            Pos now = q.poll();
            for(int direction = 0; direction < 4; direction++)
            {
                Pos next = new Pos(now.y + dY[direction], now.x + dX[direction]);
                
                while(next.y < H && next.y >= 0 && next.x < W && next.x >= 0)
                {
                    if(board[next.y][next.x] == '*')
                        break;

                    if(mask[next.y][next.x] == -1)
                    {
                        mask[next.y][next.x] = mask[now.y][now.x] + 1;
                        q.offer(new Pos(next.y, next.x));
                    }
                    
                    next.y += dY[direction];
                    next.x += dX[direction];
                }
            }
        }

        return mask[endPos.y][endPos.x] - 1;
    }
    
    private static class Pos{
        public int y;
        public int x;
        Pos(int y, int x)
        {
            this.y = y;
            this.x = x;
        }
    }
}