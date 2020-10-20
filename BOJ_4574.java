import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ_4574 {
    private static final int BOARDSIZE = 9;

    private static int[][] board;
    private static boolean[][] checkRows;
    private static boolean[][] checkCols;
    private static boolean[][] checkBlocks;
    private static boolean[][] checkTiles;
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N;
        StringTokenizer st;
        int testCase = 1;
        do{
            N = Integer.parseInt(br.readLine());
            if(N == 0)
                break;

            bw.write("Puzzle " + Integer.toString(testCase++) + "\n");

            board = new int[BOARDSIZE][BOARDSIZE];
            checkRows = new boolean[BOARDSIZE][BOARDSIZE + 1];
            checkCols = new boolean[BOARDSIZE][BOARDSIZE + 1];
            checkBlocks = new boolean[BOARDSIZE][BOARDSIZE + 1];
            checkTiles = new boolean[BOARDSIZE + 1][BOARDSIZE + 1];
            
            for(int index = 0; index < N; index++)
            {
                st = new StringTokenizer(br.readLine());
                int[] tile = new int[2];
                for(int pair = 0; pair < 2; pair++)
                {
                    int num = Integer.parseInt(st.nextToken());
                    String pos = st.nextToken();
                    int y = pos.charAt(0) - 'A';
                    int x = pos.charAt(1) - '1';
                    board[y][x] = num;

                    checkRows[y][num] = true;
                    checkCols[x][num] = true;
                    int block = y / 3 * 3 + x / 3;
                    checkBlocks[block][num] = true;
                    tile[pair] = num;
                }
                checkTiles[tile[0]][tile[1]] = true;
                checkTiles[tile[1]][tile[0]] = true;
            }

            st = new StringTokenizer(br.readLine());
            for(int num = 1; num <= 9; num++)
            {
                String pos = st.nextToken();
                int y = pos.charAt(0) - 'A';
                int x = pos.charAt(1) - '1';
                board[y][x] = num;

                checkRows[y][num] = true;
                checkCols[x][num] = true;
                int block = y / 3 * 3 + x / 3;
                checkBlocks[block][num] = true;
            }

            sudominoku(0, 0);

        }while(N > 0);

        bw.flush();
        bw.close();
        return;
    }

    private static boolean sudominoku(int y, int x) throws IOException
    {
        if(y == BOARDSIZE)
        {
            for(int row = 0; row < BOARDSIZE; row++)
            {
                for(int col = 0; col < BOARDSIZE; col++)
                {
                    bw.write(Integer.toString(board[row][col]));
                }
                bw.write("\n");
            }
            return true;
        }

        int nextY = y;
        int nextX = x + 1;
        if(nextX == BOARDSIZE)
        {
            nextY++;
            nextX = 0;
        }        

        if(board[y][x] != 0)
        {
            return sudominoku(nextY, nextX);
        }
        
        //가로
        if(x + 1 != BOARDSIZE && board[y][x + 1] == 0)
        {
            for(int num1 = 1; num1 <= 9; num1++)
            {
                for(int num2 = 1; num2 <= 9; num2++)
                {
                    if(num1 == num2)
                        continue;

                    int block1 = y / 3 * 3 + x / 3;
                    int block2 = y / 3 * 3 + (x + 1) / 3;

                    if(!checkTiles[num1][num2])
                    {
                        if(!checkRows[y][num1] && !checkCols[x][num1] && !checkBlocks[block1][num1])
                        {
                            if(!checkRows[y][num2] && !checkCols[x + 1][num2] && !checkBlocks[block2][num2])
                            {
                                checkTiles[num1][num2] = true;
                                checkTiles[num2][num1] = true;
                                checkRows[y][num1] = true;
                                checkCols[x][num1] = true;
                                checkBlocks[block1][num1] = true;
                                board[y][x] = num1;
                                checkRows[y][num2] = true;
                                checkCols[x + 1][num2] = true;
                                checkBlocks[block2][num2] = true;
                                board[y][x + 1] = num2;
                                
                                if(sudominoku(nextY, nextX))
                                    return true;
                                
                                checkTiles[num1][num2] = false;
                                checkTiles[num2][num1] = false;
                                checkRows[y][num1] = false;
                                checkCols[x][num1] = false;
                                checkBlocks[block1][num1] = false;
                                board[y][x] = 0;
                                checkRows[y][num2] = false;
                                checkCols[x + 1][num2] = false;
                                checkBlocks[block2][num2] = false;
                                board[y][x + 1] = 0;
                            }
                        }
                    }
                    
                }
            }
        }


        //세로
        if(y + 1 != BOARDSIZE && board[y + 1][x] == 0)
        {
            for(int num1 = 1; num1 <= 9; num1++)
            {
                for(int num2 = 1; num2 <= 9; num2++)
                {
                    if(num1 == num2)
                        continue;

                    int block1 = y / 3 * 3 + x / 3;
                    int block2 = (y + 1) / 3 * 3 + x / 3;

                    if(!checkTiles[num1][num2])
                    {
                        if(!checkRows[y][num1] && !checkCols[x][num1] && !checkBlocks[block1][num1])
                        {
                            if(!checkRows[y + 1][num2] && !checkCols[x][num2] && !checkBlocks[block2][num2])
                            {
                                checkTiles[num1][num2] = true;
                                checkTiles[num2][num1] = true;
                                checkRows[y][num1] = true;
                                checkCols[x][num1] = true;
                                checkBlocks[block1][num1] = true;
                                board[y][x] = num1;
                                checkRows[y + 1][num2] = true;
                                checkCols[x][num2] = true;
                                checkBlocks[block2][num2] = true;
                                board[y + 1][x] = num2;
                                
                                if(sudominoku(nextY, nextX))
                                    return true;
                                
                                checkTiles[num1][num2] = false;
                                checkTiles[num2][num1] = false;
                                checkRows[y][num1] = false;
                                checkCols[x][num1] = false;
                                checkBlocks[block1][num1] = false;
                                board[y][x] = 0;
                                checkRows[y + 1][num2] = false;
                                checkCols[x][num2] = false;
                                checkBlocks[block2][num2] = false;
                                board[y + 1][x] = 0;
                            }
                        }
                    }
                    
                }
            }
        }
        
        return false;
    }
}
