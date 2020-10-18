import java.util.Scanner;

public class BOJ_9663 {
    private static final int[] dY = new int[]{-1, -1, 1, 1};
    private static final int[] dX = new int[]{-1, 1, -1, 1};

    private static int answer = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.close();

        int[][] board = new int[N][N];

        findQueen(board, 0);

        System.out.println(answer);
    }

    private static void findQueen(int[][] board, int y)
    {
        int N = board.length;
        if(N == y)
        {
            answer++;
            return;
        }
        
        for(int col = 0; col < N; col++)
        {
            if(board[y][col] == 0)
            {
                mark(board, y, col);
                findQueen(board, y + 1);
                eraseMark(board, y, col);
            }
        }

        return;
    }

    private static void mark(int[][] board, int y, int x)
    {
        int N = board.length;
        for(int row = 0; row < N; row++)//세로
        {
            board[row][x]++;
        }
        for(int col = 0; col < N; col++)//가로
        {
            board[y][col]++;
        }
        for(int direction = 0; direction < 4; direction++)
        {
            int m_y = y + dY[direction];
            int m_x = x + dX[direction];
            while(m_y >= 0 && m_x >= 0 && m_y < N && m_x < N)
            {
                board[m_y][m_x]++;
                
                m_y += dY[direction];
                m_x += dX[direction];
            }
        }

        return;
    }

    private static void eraseMark(int[][] board, int y, int x)
    {
        int N = board.length;
        for(int row = 0; row < N; row++)//세로
        {
            board[row][x]--;
        }
        for(int col = 0; col < N; col++)//가로
        {
            board[y][col]--;
        }
        for(int direction = 0; direction < 4; direction++)
        {
            int m_y = y + dY[direction];
            int m_x = x + dX[direction];
            while(m_y >= 0 && m_x >= 0 && m_y < N && m_x < N)
            {
                board[m_y][m_x]--;

                m_y += dY[direction];
                m_x += dX[direction];
            }
        }

        return;
    }
}
