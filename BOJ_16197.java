import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_16197 {
    private static final boolean BLANK = false;
    private static final boolean WALL = true;
    private static final int MAX_PUSH_BUTTON = 11;
    private static final int[] dY = new int[]{-1, 0 , 1, 0};
    private static final int[] dX = new int[]{0, 1 , 0, -1};

    private static int minPush;
    private static boolean[][] board;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N, M;
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new boolean[N][M];
        Pos[] coinPos = new Pos[2];
        int coinCount = 0;
        for(int row = 0; row < N; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < M; col++)
            {
                char boardData = line.charAt(col);
                if(boardData == 'o')
                {
                    board[row][col] = BLANK;
                    coinPos[coinCount++] = new Pos(row, col);
                }
                else if(boardData == '.')
                {
                    board[row][col] = BLANK;
                }
                else if(boardData == '#')
                {
                    board[row][col] = WALL;
                }
            }
        }

        minPush = MAX_PUSH_BUTTON;
        moveCoin(1, coinPos);

        if(minPush >= MAX_PUSH_BUTTON)
        {
            minPush = -1;
        }
        System.out.println(minPush);

        return;
    }
    
    private static void moveCoin(int pushCount,Pos[] coinPos)
    {
        if(pushCount == MAX_PUSH_BUTTON)
            return;
        
        int fallCoinCount = 0;
        for(int direction = 0; direction < 4; direction++)
        {
            Pos[] nextPos = new Pos[2];
            nextPos[0] = new Pos(coinPos[0].y + dY[direction], coinPos[0].x + dX[direction]);
            nextPos[1] = new Pos(coinPos[1].y + dY[direction], coinPos[1].x + dX[direction]);

            fallCoinCount = getFallCoinCount(nextPos);

            if(fallCoinCount == 1)
            {
                if(minPush > pushCount)
                {
                    minPush = pushCount;
                }
                return;
            }
            else if(fallCoinCount == 2)
            {
                continue;
            }

            for(int coin = 0; coin < 2; coin++)
            {
                if(board[nextPos[coin].y][nextPos[coin].x] == WALL)
                {
                    nextPos[coin].y = coinPos[coin].y;
                    nextPos[coin].x = coinPos[coin].x;
                }
            }

            if(nextPos[0].y == nextPos[1].y && nextPos[0].x == nextPos[1].x)
            {
                continue;
            }

            moveCoin(pushCount + 1, nextPos);
        }
    }

    private static int getFallCoinCount(Pos[] coinPos)
    {
        int N = board.length;
        int M = board[0].length;
        int fallCointCount = 0;

        for(int coin = 0; coin < 2; coin++)
        {
            int y = coinPos[coin].y;
            int x = coinPos[coin].x;
            if(y >= N || y< 0 || x >= M || x < 0)
            {
                fallCointCount++;
            }
        }
        
        return fallCointCount;
    }
    
    private static class Pos{
        public int y;
        public int x;

        public Pos(int y,int x){
            this.y = y;
            this.x = x;
        }
    }
}
