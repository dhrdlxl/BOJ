import java.util.*;
import java.io.*;

public class BOJ_16236 {
    private static final int INF = 987654321;
    private static final int[] dY = new int[]{-1, 0, 1, 0};
    private static final int[] dX = new int[]{0, -1, 0, 1};
    private static int babySharkSize = 2;
    private static int babySharkEat = 0;
    private static Pos babySharkPos = new Pos();
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[][] board = new int[N][N];

        for(int row = 0; row < N; row++)
        {
            st = new StringTokenizer(br.readLine());
            for(int col = 0; col < N; col++)
            {
                board[row][col] = Integer.parseInt(st.nextToken());
                if(board[row][col] == 9)
                {
                    board[row][col] = 0;
                    babySharkPos.y = row;
                    babySharkPos.x = col;
                }
            }
        }

        int answer = 0;
        while(true)
        {
            int result = simulation(board);
            if(result == INF)
                break;
            answer += result;
            if(babySharkSize == babySharkEat)
            {
                babySharkEat = 0;
                babySharkSize++;
            }
        }

        System.out.println(answer);

        return;
    }

    private static int simulation(int[][] board)
    {
        int[][] mask = new int[board.length][board[0].length];
        for(int row = 0; row < board.length; row++)
        {
            for(int col = 0; col < board[0].length; col++)
            {
                mask[row][col] = -1;
            }
        }
        int count = INF;
        Queue<Pos> q = new LinkedList<>();
        q.offer(babySharkPos);
        mask[babySharkPos.y][babySharkPos.x] = 0;
        Pos fish = new Pos(INF, INF);

        while(!q.isEmpty())
        {
            Pos now = q.poll();
            if(mask[now.y][now.x] > count)
                continue;
            if(board[now.y][now.x] < babySharkSize && board[now.y][now.x] != 0)//eat
            {
                if(count == INF)
                    count = mask[now.y][now.x];
                if(fish.y > now.y)
                {
                    fish.y = now.y;
                    fish.x = now.x;
                }
                else if(fish.y == now.y)
                {
                    if(fish.x > now.x)
                    {
                        fish.y = now.y;
                        fish.x = now.x;
                    }
                }
                continue;
            }
            
            if(mask[now.y][now.x] == count)
                continue;

            for(int direction = 0; direction < 4; direction++)
            {
                Pos next = new Pos(now.y + dY[direction], now.x + dX[direction]);
                if(next.y < 0 || next.y >= board.length || next.x < 0 || next.x >= board[0].length)
                    continue;
                if(mask[next.y][next.x] == -1)
                {
                    if(board[next.y][next.x] <= babySharkSize || board[next.y][next.x] == 0)//move
                    {
                        mask[next.y][next.x] = mask[now.y][now.x] + 1;
                        q.offer(new Pos(next.y, next.x));
                    }
                }
            }
        }
        if(count != INF)
        {
            board[fish.y][fish.x] = 0;
            babySharkEat++;
            babySharkPos.y = fish.y;
            babySharkPos.x = fish.x;
        }

        return count;
    }

    private static class Pos
    {
        public int y;
        public int x;
        Pos(int y, int x)
        {
            this.y = y;
            this.x = x;
        }
        Pos(){}
    }
}
