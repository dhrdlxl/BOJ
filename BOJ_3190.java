import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ_3190 {
    private static final int BLANK = 0;
    private static final int APPLE = 1;
    private static final int SNAKE = 2;

    private static final int RIGHT = 0;
    private static final int UP = 1;
    private static final int LEFT = 2;
    private static final int DOWN = 3;

    private static int[][] move = new int[][]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[][] board = new int[N][N];
        
        int K = Integer.parseInt(br.readLine());
        StringTokenizer st;    
        for(int index = 0; index < K; index++)
        {
            st = new StringTokenizer(br.readLine());
            int row = Integer.parseInt(st.nextToken()) - 1;
            int col = Integer.parseInt(st.nextToken()) - 1;
            board[row][col] = APPLE;
        }

        int L = Integer.parseInt(br.readLine());
        LinkedList<Pair> changeInfo = new LinkedList<Pair>();
        for(int index = 0; index < L; index++)
        {
            st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken());
            if(st.nextToken().compareTo("L") == 0)
            {
                changeInfo.add(new Pair(X, LEFT));
            }
            else
            {
                changeInfo.add(new Pair(X, RIGHT));
            }
        }
        
        LinkedList<Pair> Snake = new LinkedList<Pair>();        
        int direction = RIGHT;
        int time = 0;
        
        Snake.add(new Pair(0, 0));
        board[0][0] = SNAKE;
    
        while(time < 10000)
        {
            time++;
            
            //뱀 이동
            Pair head = Snake.getLast();
            Pair nextPos = new Pair(head.y + move[direction][0], head.x + move[direction][1]);
            if(nextPos.y < 0 || nextPos.y >= N || nextPos.x < 0 || nextPos.x >= N)//벽
            {
                break;
            }
            
            int next = board[nextPos.y][nextPos.x];

            if(next == APPLE)
            {
                board[nextPos.y][nextPos.x] = SNAKE;
                Snake.addLast(nextPos);
            }
            else if(next == BLANK)
            {
                board[nextPos.y][nextPos.x] = SNAKE;
                Snake.addLast(nextPos);

                Pair tail = Snake.getFirst();
                Snake.removeFirst();
                board[tail.y][tail.x] = BLANK;
            }
            else if(next == SNAKE)
            {
                break;
            }
            //방향 변환
            if(!changeInfo.isEmpty() && changeInfo.getFirst().y == time)
            {
                int rotateDirection = changeInfo.getFirst().x;
                changeInfo.removeFirst();
                
                if(rotateDirection == LEFT)
                {
                    direction = (direction + 1) % 4;
                }
                else if(rotateDirection == RIGHT)
                {
                    direction = (direction - 1 + 4) % 4;
                }
            }
        }

        bw.write(Integer.toString(time));
        bw.flush();
        bw.close();
        return;
    }

    private static class Pair
    {
        public int y;
        public int x;
        Pair(int y, int x)
        {
            this.y = y;
            this.x = x;
        }
    }
}
