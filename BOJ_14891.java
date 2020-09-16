import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;


public class BOJ_14891 {
    private static boolean[] mask;
    private static int[][] gears;

    private static final int SAWTOOTH = 8;//톱니
    private static final int GEAR = 5;//톱니바퀴(1 ~ 4)
    private static final int LEFTSAWTOOTH = 6;
    private static final int RIGHTSAWTOOTH = 2;
    private static final int S_POLE = 1;//S극
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        gears = new int[GEAR][SAWTOOTH];

        for(int index = 1; index <= 4; index++)
        {
            String gear = br.readLine();
            for(int sawtooth = 0; sawtooth < SAWTOOTH; sawtooth++)
            {
                gears[index][sawtooth] = gear.charAt(sawtooth) - '0';
            }
        }

        int turnCount = Integer.parseInt(br.readLine());
        StringTokenizer st;

        for(int index = 0; index < turnCount; index++)
        {
            st = new StringTokenizer(br.readLine());
            int targetGear = Integer.parseInt(st.nextToken());
            int direction = Integer.parseInt(st.nextToken());
            mask = new boolean[GEAR];

            turn(targetGear, direction);
        }
        
        int answer = 0;
        int point = 1;
        for(int index = 1; index < GEAR; index++)
        {
            if(gears[index][0] == S_POLE)
            {
                answer += point;
            }
            point *= 2;
        }

        bw.write(Integer.toString(answer));
        bw.flush();
        bw.close();
        return;
    }

    private static void turn(int gear, int direction)
    {
        if(mask[gear] == false)
        {
            mask[gear] = true;
            
            int leftGear = gear - 1;
            int rightGear = gear + 1;
            if(leftGear > 0 && mask[leftGear] == false)
            {
                if(gears[leftGear][RIGHTSAWTOOTH] != gears[gear][LEFTSAWTOOTH])
                turn(leftGear, direction * -1);
            }
            
            if(rightGear < GEAR && mask[rightGear] == false)
            {
                if(gears[gear][RIGHTSAWTOOTH] != gears[rightGear][LEFTSAWTOOTH])
                turn(rightGear, direction * -1);
            }


            if(direction == 1)//turn right
            {
                int temp = gears[gear][SAWTOOTH - 1];
                for(int index = SAWTOOTH - 1; index >= 1; index--)
                {
                    gears[gear][index] = gears[gear][index - 1];
                }
                gears[gear][0] = temp;
            }
            else if(direction == -1)//turn left
            {
                int temp = gears[gear][0];
                for(int index = 0; index < SAWTOOTH - 1; index++)
                {
                    gears[gear][index] = gears[gear][index + 1];
                }
                gears[gear][SAWTOOTH - 1] = temp;
            }
            
            return;
        }
        
        return;
    }
}
