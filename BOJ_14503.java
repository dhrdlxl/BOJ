import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class BOJ_14503 {
    private static int[][] board;
    private static int answer;
    private static final int Y = 0;
    private static final int X = 1;
    private static boolean[][] cleaned;
    private static int N;
    private static int M;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int y = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int direction = Integer.parseInt(st.nextToken());//북, 동, 남, 서

        board = new int[N][M];
        cleaned = new boolean[N][M];

        for(int row = 0; row < N; row++)
        {
            st = new StringTokenizer(br.readLine());
            for(int col = 0; col < M; col++)
            {
                board[row][col] = Integer.parseInt(st.nextToken());
            }
        }
        
        answer = 0;

        move(y, x, direction);
        
        bw.write(Integer.toString(answer));
        bw.flush();
        bw.close();

        return;
    }
    private static void move(int y, int x, int direction)
    {
        //clean
        if(cleaned[y][x] == false && board[y][x] == 0)
        {
            cleaned[y][x] = true;
            answer++;
        }

        //move
        boolean checkMove = false;
        for(int index = 0; index < 4; index++)
        {
            int[] leftPos = findLeft(y, x, direction);
            if(!isWall(leftPos) && !cleaned[leftPos[Y]][leftPos[X]])
            {
                direction = (direction + 4 - 1) % 4;
                checkMove = true;
                move(leftPos[Y], leftPos[X], direction);
                break;
            }
            else
            {
                direction = (direction + 4 - 1) % 4;
            }
        }

        if(checkMove == false)
        {
            int[] backPos = moveBack(y, x, direction);
            //종료
            if(isWall(backPos))
            {
                return;
            }
            //후진
            else
            {
                move(backPos[Y], backPos[X], direction);
            }
        }
        return;
    }

    private static int[] moveBack(int y, int x, int direction)
    {
        int[] backPos = new int[]{y, x};
        
        if(direction == 0)//북
        {
            backPos[Y]++;
        }
        else if(direction == 1)//동
        {
            backPos[X]--;
        }
        else if(direction == 2)//남
        {
            backPos[Y]--;
        }
        else if(direction == 3)//서
        {
            backPos[X]++;
        }

        return backPos;
    }

    private static boolean isWall(int[] pos)
    {
        if(board[pos[Y]][pos[X]] == 1)//주어진 벽
            return true;
        return false;
    }

    private static int[] findLeft(int y, int x, int direction)
    {
        int[] pos = new int[]{y, x};
        if(direction == 0)//북
        {
            pos[X]--;
        }
        else if(direction == 1)//동
        {
            pos[Y]--;
        }
        else if(direction == 2)//남
        {
            pos[X]++;
        }
        else if(direction == 3)//서
        {
            pos[Y]++;
        }
        return pos;
    }
}
