import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.io.IOException;


public class BOJ_15686 {
    private static final int HOUSE = 1;
    private static final int CHICKEN = 2;
    private static final int MAXVALUE = 2500;
    private static int answer = MAXVALUE;
    private static int[][] chickenDistances;
    private static int mask = 0;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;
        LinkedList<Pos> houseList = new LinkedList<Pos>();
        LinkedList<Pos> chickenList = new LinkedList<Pos>();

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for(int row = 1; row <= N; row++)
        {
            st = new StringTokenizer(br.readLine());
            for(int col = 1; col <= N; col++)
            {
                int type = Integer.parseInt(st.nextToken());
                if(type == HOUSE)
                {
                    houseList.add(new Pos(row, col));
                }
                else if(type == CHICKEN)
                {
                    chickenList.add(new Pos(row, col));
                }
            }
        }

        chickenDistances = new int[chickenList.size()][houseList.size()];

        for(int index = 0; index < houseList.size(); index++)
        {
            for(int chickenIndex = 0; chickenIndex < chickenList.size(); chickenIndex++)
            {
                int dY = houseList.get(index).y - chickenList.get(chickenIndex).y;
                int dX = houseList.get(index).x - chickenList.get(chickenIndex).x;

                if(dY < 0)
                    dY *= -1;
                if(dX < 0)
                    dX *= -1;

                int distance = dY + dX;
                
                chickenDistances[chickenIndex][index] = distance;
            }
        }

        combination(0, 0, M);

        bw.write(Integer.toString(answer));
        bw.flush();
        bw.close();

        return;
    }
    private static void combination(int start, int step, int finish)
    {
        if(step == finish)
        {
            int distance = getDistance();
            if(distance < answer)
            {
                answer = distance;
            }
                return;
        }

        for(int index = start; index < chickenDistances.length; index++)
        {
            if((mask & (1 << index)) == 0)
            {
                mask |= (1 << index);
                combination(index, step + 1, finish);
                mask ^= (1 << index);
            }
        }
        return;
    }

    private static int getDistance()
    {
        int distance = 0;
        int houseCount = chickenDistances[0].length;
        int chickenCount = chickenDistances.length;
        int[] minDistances = new int[houseCount];

        for(int index = 0; index < houseCount; index++)
            minDistances[index] = MAXVALUE;
        
        for(int index = 0; index < chickenCount; index++)
        {
            if((mask & (1 << index)) != 0)
            {
                for(int houseIndex = 0; houseIndex < houseCount; houseIndex++)
                {
                    if(minDistances[houseIndex] > chickenDistances[index][houseIndex])
                        minDistances[houseIndex] = chickenDistances[index][houseIndex];
                }
            }
        }

        for(int dist : minDistances)
            distance += dist;

        return distance;
    }

    private static class Pos
    {
        public int y;
        public int x;
        Pos(int m_y, int m_x)
        {
            y = m_y;
            x = m_x;
        } 
    }
}
