import java.io.*;
import java.util.*;

public class BOJ_1780_2 {
    private static final int FALSE = -987654321;

    private static int[] answer = new int[3];
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

        find(0, 0, N, board);

        for(int index = 0; index < 3; index++)
        {
            System.out.println(answer[index]);
        }
    }

    private static void find(int rowBegin, int colBegin, int length, int[][] board)
    {
        int checkNum = board[rowBegin][colBegin];
        for(int row = rowBegin; row < rowBegin + length; row++)
        {
            for(int col = colBegin; col < colBegin + length; col++)
            {
                if(checkNum != board[row][col])
                {
                    checkNum = FALSE;
                    break;
                }
            }
        }

        if(checkNum == FALSE)
        {
            int nextLength = length / 3;
            for(int row = 0; row < 3; row++)
            {
                for(int col = 0; col < 3; col++)
                {
                    find(rowBegin + row * nextLength, colBegin + col * nextLength, nextLength, board);
                }
            }
        }
        else
        {
            answer[checkNum + 1]++;
        }
    }
}