import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

class mapInfo{
    int fishNumber;
    int dir;
}
class pos{
    int x;
    int y;
    public pos(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
}

public class BOJ_19236 {
    public static final int[][] move = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    public static final int moveSize = 8;
    public static final int mapSize = 4;
    public static int answer = 0;

    public static void DFS(pos shark, mapInfo[][] map, int sum)
    {
        sum += map[shark.x][shark.y].fishNumber;
        map[shark.x][shark.y].fishNumber = -1; //상어가 먹으면 -1

        if(sum > answer)
            answer = sum;

        //물고기 이동
        for(int fishNumber = 1; fishNumber <=16; fishNumber++)
        {
            boolean check = true;
            for(int row = 0; (row < mapSize) && check; row++)
            {
                for(int col = 0; (col < mapSize) && check; col++)
                {
                    if(fishNumber == map[row][col].fishNumber)
                    {
                        check = false;

                        int dirSearch = 0;
                        while(dirSearch < moveSize)
                        {
                            int m_dir = (map[row][col].dir + dirSearch) % moveSize;
                            int m_x = row + move[m_dir][0];
                            int m_y = col + move[m_dir][1];
                            if((m_x >= 0) && (m_x < mapSize) && (m_y >=0) && (m_y < mapSize))
                            {
                                if((m_x != shark.x) || (m_y != shark.y))
                                {
                                    //swap
                                    mapInfo temp = new mapInfo();
                                    temp = map[row][col];
                                    map[row][col] = map[m_x][m_y];
                                    map[m_x][m_y] = temp;
                                    map[m_x][m_y].dir = m_dir;
                                    break;
                                }
                            }
                            dirSearch++;
                        }
                    }
                }
            }
        }

        //상어 이동
        int sharkDir = map[shark.x][shark.y].dir;

        for(int index = 0; index < 3; index++)
        {
            shark.x += move[sharkDir][0];
            shark.y += move[sharkDir][1];

            if(shark.x < 0 || shark.x >= mapSize || shark.y <0 || shark.y >= mapSize)
                break;
            if(map[shark.x][shark.y].fishNumber == -1)// 빈칸
                continue;
                
            mapInfo[][] mapCopy = new mapInfo[mapSize][mapSize];
            for(int row = 0; row < mapSize; row++)
            {
                for(int col = 0; col < mapSize; col++)
                {
                    mapCopy[row][col] = new mapInfo();
                    mapCopy[row][col].fishNumber = map[row][col].fishNumber;
                    mapCopy[row][col].dir = map[row][col].dir;
                    // mapCopy[row][col] = map[row][col];
                }
            }
            DFS(new pos(shark.x, shark.y), mapCopy, sum);
        }
    }

    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        mapInfo[][] map = new mapInfo[mapSize][mapSize];

        for(int row = 0; row < mapSize; row++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int col = 0; col < mapSize; col++)
            {
                int fishNumber = Integer.parseInt(st.nextToken());
                int dir = Integer.parseInt(st.nextToken());
                
                map[row][col] = new mapInfo();
                map[row][col].fishNumber = fishNumber;
                map[row][col].dir = dir - 1;
            }
        }

        DFS(new pos(0,0), map, 0);

        bw.write(Integer.toString(answer));
        bw.flush();
        bw.close();
    }    
}