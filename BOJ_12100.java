import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_12100 {
    private static final int MAX_MOVE = 5;
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
            }
        }

        int answer = 0;
        for(int occation = 0; occation < (1 << MAX_MOVE * 2); occation++)
        {
            int[] directions = genDirection(occation);

            int[][] copyBoard = new int[N][N];
            for(int row = 0; row < N; row++)
            {
                copyBoard[row] = board[row].clone();
            }
            answer = max(answer, simulation(directions, copyBoard));
        }

        System.out.println(answer);
        return;
    }

    private static int simulation(int[] directions, int[][] board)
    {
        int max = 0;
        
        for(int step = 0; step < MAX_MOVE; step++)
        {
            int direction = directions[step];

            //위
            if(direction == 0)
            {
                int index = 0;
                int beforeNum = 0;
                for(int col = 0; col < board.length; col++)
                {
                    beforeNum = 0;
                    index = 0;
                    for(int row = 0 ; row <board.length; row++)
                    {
                        if(board[row][col] != 0)
                        {
                            if(beforeNum == 0)
                            {
                                beforeNum = board[row][col];
                                board[row][col] = 0;
                            }
                            else if(beforeNum == board[row][col])
                            {
                                board[row][col] = 0;
                                board[index++][col] = 2 * beforeNum;
                                beforeNum = 0;
                            }
                            else if(beforeNum != board[row][col])
                            {
                                board[index++][col] = beforeNum;
                                beforeNum = board[row][col];
                                board[row][col] = 0;
                            }
                        }
                    }
                    if(beforeNum != 0)
                    {
                        board[index][col] = beforeNum;
                    }
                }
            }

            //왼쪽
            else if(direction == 1)
            {
                int index = 0;
                int beforeNum = 0;
                for(int row = 0; row < board.length; row++)
                {
                    beforeNum = 0;
                    index = 0;
                    for(int col = 0 ; col <board.length; col++)
                    {
                        if(board[row][col] != 0)
                        {
                            if(beforeNum == 0)
                            {
                                beforeNum = board[row][col];
                                board[row][col] = 0;
                            }
                            else if(beforeNum == board[row][col])
                            {
                                board[row][col] = 0;
                                board[row][index++] = 2 * beforeNum;
                                beforeNum = 0;
                            }
                            else if(beforeNum != board[row][col])
                            {
                                board[row][index++] = beforeNum;
                                beforeNum = board[row][col];
                                board[row][col] = 0;
                            }
                        }
                    }
                    if(beforeNum != 0)
                    {
                        board[row][index] = beforeNum;
                    }
                }
            }

            //아래
            else if(direction == 2)
            {
                int index = board.length - 1;
                int beforeNum = 0;
                for(int col = 0; col < board.length; col++)
                {
                    beforeNum = 0;
                    index = board.length - 1;
                    for(int row = board.length - 1 ; row >= 0; row--)
                    {
                        if(board[row][col] != 0)
                        {
                            if(beforeNum == 0)
                            {
                                beforeNum = board[row][col];
                                board[row][col] = 0;
                            }
                            else if(beforeNum == board[row][col])
                            {
                                board[row][col] = 0;
                                board[index--][col] = 2 * beforeNum;
                                beforeNum = 0;
                            }
                            else if(beforeNum != board[row][col])
                            {
                                board[index--][col] = beforeNum;
                                beforeNum = board[row][col];
                                board[row][col] = 0;
                            }
                        }
                    }
                    if(beforeNum != 0)
                    {
                        board[index][col] = beforeNum;
                    }
                }
            }

            // 오른쪽
            else if(direction == 3)
            {
                int index = board.length - 1;
                int beforeNum = 0;
                for(int row = 0; row < board.length; row++)
                {
                    beforeNum = 0;
                    index = board.length - 1;
                    for(int col = board.length - 1; col >= 0; col--)
                    {
                        if(board[row][col] != 0)
                        {
                            if(beforeNum == 0)
                            {
                                beforeNum = board[row][col];
                                board[row][col] = 0;
                            }
                            else if(beforeNum == board[row][col])
                            {
                                board[row][col] = 0;
                                board[row][index--] = 2 * beforeNum;
                                beforeNum = 0;
                            }
                            else if(beforeNum != board[row][col])
                            {
                                board[row][index--] = beforeNum;
                                beforeNum = board[row][col];
                                board[row][col] = 0;
                            }
                        }
                    }
                    if(beforeNum != 0)
                    {
                        board[row][index] = beforeNum;
                    }
                }
            }

        }

        for(int row = 0; row < board.length; row++)
        {
            for(int col = 0; col < board.length; col++)
            {
                if(board[row][col] != 0)
                {
                    max = max(max, board[row][col]);
                }
            }
        }
        return max;
    }

    private static int max(int a, int b)
    {
        return a > b ? a : b;
    }

    private static int[] genDirection(int occation)
    {
        int[] directions = new int[MAX_MOVE];

        for(int index = 0; index < MAX_MOVE; index++)
        {
            directions[index] = (occation & 3);
            occation >>= 2;
        }

        return directions;
    }
}
