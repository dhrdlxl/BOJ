import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2580 {
    private static final int BOARDSIZE = 9;
    private static boolean[][] checkRow = new boolean[BOARDSIZE][BOARDSIZE + 1];
    private static boolean[][] checkCol = new boolean[BOARDSIZE][BOARDSIZE + 1];
    private static boolean[][] checkBlock = new boolean[BOARDSIZE][BOARDSIZE + 1];
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;
        int[][] board = new int[BOARDSIZE][BOARDSIZE];

        for(int row = 0; row < BOARDSIZE; row++)
        {
            st = new StringTokenizer(br.readLine());
            for(int col = 0; col < BOARDSIZE; col++)
            {
                board[row][col] = Integer.parseInt(st.nextToken());
                checkRow[row][board[row][col]] = true;
                checkCol[col][board[row][col]] = true;
                int block = row / 3 * 3 + col / 3;
                checkBlock[block][board[row][col]] = true;
            }
        }
        
        sudoku(board, 0, 0);
        
        return;
    }

    private static boolean sudoku(int[][] board, int y, int x)
    {
        if(y == BOARDSIZE && x == 0)
        {
            for(int row = 0; row < BOARDSIZE; row++)
            {
                for(int col = 0; col < BOARDSIZE; col++)
                {
                    System.out.print(board[row][col] + " ");
                }
                System.out.print("\n");
            }
            return true;
        }
        
        int nextX = (x + 1) % BOARDSIZE;
        int nextY = y;
        if(x + 1 == BOARDSIZE)
            nextY++;
        if(board[y][x] != 0)
            return sudoku(board, nextY, nextX);
        
        for(int num = 1; num <= BOARDSIZE; num++)
        {
            int block = y / 3 * 3 + x / 3;
            if(!checkRow[y][num] && !checkCol[x][num] && !checkBlock[block][num])
            {
                checkRow[y][num] = true;
                checkCol[x][num] = true;
                checkBlock[block][num] = true;
                board[y][x] = num;

                if(sudoku(board, nextY, nextX))
                {
                    return true;
                }

                checkRow[y][num] = false;
                checkCol[x][num] = false;
                checkBlock[block][num] = false;
                board[y][x] = 0;
            }
        }

        return false;
    }
}
