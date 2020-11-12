import java.io.*;

public class BOJ_2138 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        boolean[] A = new boolean[N];
        boolean[] B = new boolean[N];

        String line = br.readLine();
        for(int index = 0; index < line.length(); index++)
            if(line.charAt(index) == '1')
                A[index] = true;

        line = br.readLine();
        for(int index = 0; index < line.length(); index++)
            if(line.charAt(index) == '1')
                B[index] = true;

        boolean[] aCopy = A.clone();
        if(isSame(aCopy, B, 0))
            return;

        aCopy = A.clone();
        aCopy[0] = !aCopy[0];
        aCopy[1] = !aCopy[1];
        if(isSame(aCopy, B, 1))
            return;

        System.out.println(-1);
        return;
    }
    private static boolean isSame(boolean[] A, boolean[] B, int answer)
    {
        int N = A.length;

        for(int index = 1; index < N; index++)
        {
            if(A[index - 1] != B[index - 1])
            {
                answer++;

                int left = index - 1;
                int right = index + 1;
                if(right == N)
                    right--;
                for(int i = left; i <=right; i++)
                {
                    A[i] = !A[i];
                }
            }
        }

        if(A[N - 1] == B[N - 1])
        {
            System.out.println(answer);
            return true;
        }
        return false;
    }
}