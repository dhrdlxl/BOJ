import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ_17136 {
    private static final int N = 10;
    private static final int MAX = 5*5+1;
    private static int[][] map;
    private static int[] leftPaper = new int[]{5,5,5,5,5};
    private static int minUsedPaper = MAX;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;
        map = new int[N][N];
        Pos startPos = null;

        for(int row = 0; row < N; row++)
        {
            st = new StringTokenizer(br.readLine());
            int col = 0;
            while(st.hasMoreTokens())
            {
                map[row][col] = Integer.parseInt(st.nextToken());
                if(map[row][col] == 1)
                {
                    if(startPos == null)
                    {
                        startPos = new Pos(row, col);
                    }
                }
                col++;
            }
        }

        simulation(0, startPos);//사용한 종이 개수, 남은 1 개수, 좌표 (y, x)

        if(minUsedPaper == MAX)
            minUsedPaper = -1;
        
        bw.write(Integer.toString(minUsedPaper));
        bw.flush();
        bw.close();
        
        return;
    }

    private static void simulation(int usedPaper, Pos nowPos)
    {
        if(nowPos == null)
        {
            if(usedPaper < minUsedPaper)
                minUsedPaper = usedPaper;
            return;
        }
        else if(usedPaper > minUsedPaper)//Back_Tracking
            return;

        for(int index = 0; index < 5; index++)
        {
            if(leftPaper[index] > 0)
            {
                if(attach(nowPos, index+1))
                {
                    leftPaper[index]--;
                    Pos nextPos = null;
                    findNext:
                    for(int row = nowPos.y; row < N; row++)
                    {
                        for(int col = 0; col < N; col++)
                        {
                            if(map[row][col] == 1)
                            {
                                nextPos = new Pos(row, col);
                                break findNext;
                            }
                        }
                    }

                    simulation(usedPaper + 1, nextPos);
                    
                    leftPaper[index]++;
                    detach(nowPos, index + 1);
                }
            }
        }
        return;
    }

    private static boolean attach(Pos pos, int paperSize)
    {
        if(pos.y + paperSize > N || pos.x + paperSize > N)
            return false;

        for(int row = pos.y; row < pos.y + paperSize; row++)
        {
            for(int col = pos.x; col < pos.x + paperSize; col++)
            {
                if(map[row][col] == 0)
                {
                    return false;
                }
            }
        }

        for(int row = pos.y; row < pos.y + paperSize; row++)
        {
            for(int col = pos.x; col < pos.x + paperSize; col++)
            {
                map[row][col] = 0;
            }
        }
        return true;
    }

    private static void detach(Pos pos, int paperSize)
    {
        for(int row = pos.y; row < pos.y + paperSize; row++)
        {
            for(int col = pos.x; col < pos.x + paperSize; col++)
            {
                map[row][col] = 1;
            }
        }
    }

    private static class Pos
    {
        public int y;
        public int x;
        Pos(){}
        Pos(int y, int x)
        {
            this.y = y;
            this.x = x;
        }
    }
}
