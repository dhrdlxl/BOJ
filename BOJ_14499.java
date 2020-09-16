import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class BOJ_14499 {
    private static Pos pos;
    private static Dice dice;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        pos = new Pos(y, x);
        int operationCount = Integer.parseInt(st.nextToken());
        int[][] board = new int[N][M];

        for(int row = 0; row < N; row++)
        {
            st = new StringTokenizer(br.readLine());
            for(int col = 0; col < M; col++)
            {
                board[row][col] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        dice = new Dice();
        for(int index = 0; index < operationCount; index++)
        {
            int operation = Integer.parseInt(st.nextToken());

            if(nextPos(N, M, operation) == false)
                continue;
            
            moveDice(operation);

            bw.write(Integer.toString(dice.up) + "\n");

            if(board[pos.y][pos.x] == 0)
            {
                board[pos.y][pos.x] = dice.down;
            }
            else
            {
                dice.down = board[pos.y][pos.x];
                board[pos.y][pos.x] = 0;
            }
        }

        bw.flush();
        bw.close();
        return;
    }

    private static void moveDice(int direction)
    {
        if(direction == 1)//East
        {
            int temp = dice.east;
            dice.east = dice.up;
            dice.up = dice.west;
            dice.west = dice.down;
            dice.down = temp;
        }
        else if(direction == 2)//West
        {
            int temp = dice.west;
            dice.west = dice.up;
            dice.up = dice.east;
            dice.east = dice.down;
            dice.down = temp;
        }
        else if(direction == 3)//North
        {
            int temp = dice.north;
            dice.north = dice.up;
            dice.up = dice.south;
            dice.south = dice.down;
            dice.down = temp;
        }
        else if(direction == 4)//South
        {
            int temp = dice.south;
            dice.south = dice.up;
            dice.up = dice.north;
            dice.north = dice.down;
            dice.down = temp;
        }
    }

    private static boolean nextPos(int N, int M, int direction)
    {
        int[][] move = new int[][]{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};//East, West, North, South
        
        Pos nextPos = new Pos(pos.y + move[direction - 1][0], pos.x + move[direction - 1][1]);
        if(nextPos.y < 0 || nextPos.x < 0 || nextPos.y >= N || nextPos.x >= M)
            return false;
        
        pos = nextPos;
        return true;
    }

    private static class Dice
    {
        public int up;
        public int down;
        public int east;
        public int west;
        public int north;
        public int south;
        Dice()
        {
            up = 0;
            down = 0;
            east = 0;
            west = 0;
            north = 0;
            south = 0;
        }
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
    }
}
