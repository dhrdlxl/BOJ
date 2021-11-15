import java.util.*;
import java.io.*;

public class BOJ_20906 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int down = s;
        int up = 0;
        
        st = new StringTokenizer(br.readLine());
        int before = Integer.parseInt(st.nextToken());

        for (int index = 1; index <= n; index++) {
            int time = 0;
            if (index < n) {
                time = Integer.parseInt(st.nextToken());
            } else {
                time = t;
            }
            int move = Math.min(time - before, down);
            before = time;
            
            //swap
            int temp = down;
            down = up;
            up = temp;

            down += move;
            up -= move;
        }

        System.out.println(up);
    }
}
