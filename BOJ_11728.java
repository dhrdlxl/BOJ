import java.util.*;
import java.io.*;

public class BOJ_11728 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] A = new int[N];
        int[] B = new int[M];

        st = new StringTokenizer(br.readLine());
        for(int index = 0; index < N; index++)
        {
            A[index] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int index = 0; index < M; index++)
        {
            B[index] = Integer.parseInt(st.nextToken());
        }

        int indexA = 0;
        int indexB = 0;

        while(indexA < A.length && indexB < B.length)
        {
            if(A[indexA] < B[indexB])
                bw.write(A[indexA++] + " ");
            else
                bw.write(B[indexB++] + " ");
        }
        while(indexA < A.length) bw.write(A[indexA++] + " ");
        while(indexB < B.length) bw.write(B[indexB++] + " ");

        bw.flush();
        bw.close();
    }
}