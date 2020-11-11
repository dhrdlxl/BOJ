import java.io.*;

public class BOJ_10026 {
    private static final int[] dY = new int[]{-1, 0, 1, 0};
    private static final int[] dX = new int[]{0, -1, 0, 1};
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        char[][] board = new char[N][N];
        char[][] boardOfColorWeakness = new char[N][N];

        for(int row = 0; row < N; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < N; col++)
            {
                board[row][col] = line.charAt(col);
                boardOfColorWeakness[row][col] = board[row][col];
                if(boardOfColorWeakness[row][col] == 'G')
                {
                    boardOfColorWeakness[row][col] = 'R';
                }
            }
        }

        int answer = findArea(N, board);
        int answerOfColorWeakness = findArea(N, boardOfColorWeakness);

        System.out.println(answer + " " + answerOfColorWeakness);
        return;
    }    

    private static int findArea(int N, char[][] board)
    {
        int areaCount = 0;
        boolean[][] mask = new boolean[N][N];

        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < N; col++)
            {
                if(mask[row][col] == false)
                {
                    areaCount++;
                    search(N, board, mask, new Pos(row, col), board[row][col]);
                }
            }
        }

        return areaCount;
    }

    private static void search(int N, char[][] board, boolean[][] mask, Pos now, char target)
    {
        mask[now.y][now.x] = true;

        for(int direction = 0; direction < 4; direction++)
        {
            Pos next = new Pos(now.y + dY[direction], now.x + dX[direction]);
            if(next.y >= N || next.y < 0 || next.x >= N || next.x < 0)
                continue;
            
            if(mask[next.y][next.x] == false && board[next.y][next.x] == target)
            {
                search(N, board, mask, next, target);
            }
        }
        return;
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
