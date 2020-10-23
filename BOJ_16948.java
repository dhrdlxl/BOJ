import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_16948 {
    private static final int Y = 0;
    private static final int X = 1;
    private static final int[] dY = new int[]{-2, -2, 0, 2, 2, 0};
    private static final int[] dX = new int[]{-1, 1, 2, 1, -1, -2};

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        Pos start, end;

        int y = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        start = new Pos(y, x);

        y = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        end = new Pos(y, x);

        int[][] mask = new int[N][N];
        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < N; col++)
            {
                mask[row][col] = -1;
            }
        }

        bfs(start, mask);

        System.out.println(mask[end.y][end.x]);

        return;
    }

    private static void bfs(Pos start, int[][] mask)
    {
        Queue<Pos> q = new LinkedList<>();
        q.offer(start);
        int N = mask.length;
        mask[start.y][start.x] = 0;

        while(!q.isEmpty())
        {
            Pos now = q.poll();
            for(int direction = 0 ; direction < 6; direction++)
            {
                Pos next = new Pos(now.y + dY[direction], now.x + dX[direction]);
                if(next.y >= N || next.x >= N || next.y < 0 || next.x < 0)
                    continue;
                if(mask[next.y][next.x] == -1)
                {
                    mask[next.y][next.x] = mask[now.y][now.x] + 1;
                    q.offer(next);
                }
            }
        }
    }

    private static class Pos
    {
        public int y;
        public int x;
        public Pos(int y, int x)
        {
            this.y = y;
            this.x = x;
        }
    }
}
