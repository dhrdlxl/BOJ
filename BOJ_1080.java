import java.util.*;
import java.io.*;
public class BOJ_1080 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        boolean[][] A = new boolean[N][M];
        boolean[][] B = new boolean[N][M];

        for(int row = 0; row < N; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < M; col++)
            {
                if(line.charAt(col) == '0')
                    A[row][col] = false;
                else
                    A[row][col] = true;
            }
        }
        for(int row = 0; row < N; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < M; col++)
            {
                if(line.charAt(col) == '0')
                    B[row][col] = false;
                else
                    B[row][col] = true;
            }
        }

        int answer = 0;
        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < M; col++)
            {
                if(A[row][col] != B[row][col])
                {
                    answer++;
                    if(change(A, row, col) == false)
                    {
                        System.out.println(-1);
                        return;
                    }
                }
            }
        }

        System.out.println(answer);

        return;
    }
    private static boolean change(boolean[][] A, int y, int x)
    {
        int endY = y + 3;
        int endX = x + 3;
        if(endY > A.length || endX > A[0].length)
        {
            return false;
        }
        for(int row = y; row < endY; row++)
        {
            for(int col = x; col < endX; col++)
            {
                A[row][col] = !A[row][col];
            }
        }
        return true;
    }
}