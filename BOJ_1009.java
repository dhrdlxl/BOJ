import java.util.*;
import java.io.*;

class BOJ_1009 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cal = a % 10;

            for (; b - 1 > 0; b--) {
                cal *= a;
                cal %= 10;
            }

            if (cal == 0)
                cal = 10;
            System.out.println(cal);
        }
    }
}