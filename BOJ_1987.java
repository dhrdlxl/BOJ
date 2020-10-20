import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1987 {
    private static final int[] dY = new int[]{-1, 0, 1, 0};
    private static final int[] dX = new int[]{0, 1, 0, -1};

    private static int R;
    private static int C;
    private static int[][] board;
    private static boolean[] mask = new boolean['Z' - 'A' + 1];

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        board = new int[R][C];

        for(int row = 0; row < R; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < C; col++)
            {
                board[row][col] = (int)(line.charAt(col) - 'A');
            }
        }

        mask[board[0][0]] = true;
        System.out.println(move(0, 0));
        return;
    }
    
    private static int move(int y, int x)
    {
        int answer = 0;

        for(int direction = 0; direction < 4; direction++)
        {
            int nextY = y + dY[direction];
            int nextX = x + dX[direction];

            if(nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
                continue;
            if(mask[board[nextY][nextX]] == false)
            {
                mask[board[nextY][nextX]] = true;

                answer = max(answer, move(nextY, nextX));

                mask[board[nextY][nextX]] = false;
            }
        }

        return answer + 1;
    }

    private static int max(int a, int b)
    {
        return a > b? a : b;
    }
}
