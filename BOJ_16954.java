import java.io.*;
import java.util.*;
public class BOJ_16954 {
    private static final int[] dY = new int[]{-1, -1, -1, 0, 0, 0, 1, 1, 1};
    private static final int[] dX = new int[]{-1, 0, 1, -1, 0, 1, -1, 0, 1};
    private static final int BOARD_SIZE = 8;
    private static final char BLANK = '.';

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[][][] board = new char[BOARD_SIZE][BOARD_SIZE][BOARD_SIZE];
        for(int row = 0; row < BOARD_SIZE; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < BOARD_SIZE; col++)
            {
                board[row][col][0] = line.charAt(col);
            }
        }
        for(int step = 1; step < BOARD_SIZE; step++)
        {
            for(int row = BOARD_SIZE - 1; row > 0; row--)
            {
                for(int col = 0; col < BOARD_SIZE; col++)
                {
                    board[row][col][step] = board[row - 1][col][step - 1];
                }
            }
            for(int col = 0; col < BOARD_SIZE; col++)
                board[0][col][step] = BLANK;
        }

        if(dfs(BOARD_SIZE - 1, 0, board, 0))
        {
            System.out.println(1);
        }
        else
            System.out.println(0);
        return;
    }

    private static boolean dfs(int y, int x, char[][][] board, int step)
    {
        if(step + 1 == BOARD_SIZE)
        {
            return true;
        }

        for(int direction = 0; direction < 9; direction++)
        {
            int nextY = y + dY[direction];
            int nextX = x + dX[direction];
            if(nextY < 0 || nextY >= BOARD_SIZE || nextX < 0 || nextX >= BOARD_SIZE)
                continue;
            if(board[nextY][nextX][step + 1] == BLANK && board[nextY][nextX][step] == BLANK)
            {
                if(dfs(nextY, nextX, board, step + 1))
                {
                    return true;
                }
            }
        }

        return false;
    }
}
