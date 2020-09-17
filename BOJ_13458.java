import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class BOJ_13458 {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int [] room = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int index = 0; index < N; index++)
        {
            room[index] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        long answer = N;
        for(int index = 0; index < N; index++)
        {
            room[index] -= B;
            int x = room[index] / C;
            if(x > 0)
            {
                answer += x;
            }

            if(room[index] % C > 0)
                    answer++;
        }
        bw.write(Long.toString(answer));
        bw.flush();
        bw.close();
    }
}