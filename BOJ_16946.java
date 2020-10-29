import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class BOJ_16946 {
    private static int[] dY = new int[]{0, -1, 0, 1};
    private static int[] dX = new int[]{-1, 0, 1, 0};
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] board = new int[N][M];
        for(int row = 0; row < N; row++)
        {
            String line = br.readLine();
            for(int col = 0; col < M; col++)
            {
                board[row][col] = (int)(line.charAt(col) - '0');
            }
        }
        
        int index = 2;
        int[] indexCount = new int[500002];
        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < M; col++)
            {
                if(board[row][col] == 0)
                {
                    board[row][col] = index;
                    indexCount[index] = (dfs(row, col, board, index) % 10);
                    index++;
                }
            }
        }


        for(int row = 0; row < N; row++)
        {
            for(int col = 0; col < M; col++)
            {
                if(board[row][col] > 1)
                {
                    bw.write(Integer.toString(0));
                }
                if(board[row][col] == 1)
                {
                    int count = 1;
                    HashSet<Integer> hashSet = new HashSet<>();
                    for(int direction = 0; direction < 4; direction++)
                    {
                        int nextY = row + dY[direction];
                        int nextX = col + dX[direction];
                        if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                            continue;
                        
                        if(board[nextY][nextX] > 1)
                        {
                            if(!hashSet.contains(board[nextY][nextX]))
                            {
                                count = (count + indexCount[board[nextY][nextX]])% 10;
                                hashSet.add(board[nextY][nextX]);
                            }
                        }
                    }

                    bw.write(Integer.toString(count));
                }
            }
            bw.write("\n");
        }

        bw.flush();
        bw.close();
        return;
    }

    private static int dfs(int y, int x, int[][] board, int index)
    {
        int count = 1;

        int N = board.length;
        int M = board[0].length;

        for(int direction = 0; direction < 4; direction++)
        {
            int nextY = y + dY[direction];
            int nextX = x + dX[direction];
            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                continue;
            
            if(board[nextY][nextX] == 0)
            {
                board[nextY][nextX] = index;
                count += dfs(nextY, nextX, board, index);
            }
        }

        return count;
    }
}