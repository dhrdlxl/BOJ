import java.util.*;
import java.io.*;

public class BOJ_1931 {
    private static final int START = 0;
    private static final int END = 1;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        int[][] conference = new int[N][2];
        for(int index = 0; index < N; index++)
        {
            st = new StringTokenizer(br.readLine());
            conference[index][START] = Integer.parseInt(st.nextToken());
            conference[index][END] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(conference, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b)
            {
                if(a[1] == b[1])
                {
                    return a[0] - b[0];
                }
                return a[1] - b[1];
            }
        });

        int answer = 0;
        int end = 0;
        for(int index = 0; index < N; index++)
        {
            if(conference[index][START] >= end)
            {
                answer++;
                end = conference[index][END];
            }
        }

        System.out.println(answer);
        return;
    }    
}