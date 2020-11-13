import java.io.*;

public class BOJ_1285 {
    private static final boolean BACK = true;
    private static final boolean FRONT = false;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        boolean[][] board = new boolean[N][N];
        for(int row = 0; row < N; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < N; col++)
            {
                if(line.charAt(col) == 'T')
                {
                    board[row][col] = BACK;
                }
            }
        }

        int answer = N * N;
        for(int order = 0; order < (1 << N); order++)//1이면 뒤집는다.
        {
            int sum = 0;
            for(int col = 0; col < N; col++)
            {
                int backCount = 0;
                for(int row = 0; row < N; row++)
                {
                    if((order & (1 << row)) > 0)
                    {
                        if(board[row][col] == FRONT)
                            backCount++;
                    }
                    else
                    {
                        if(board[row][col] == BACK)
                            backCount++;
                    }
                }
                sum += min(backCount, N - backCount);
            }
            answer = min(answer, sum);
        }

        System.out.println(answer);
        return;
    }    
    private static int min(int a, int b)
    {
        return a < b ? a : b;
    }
}