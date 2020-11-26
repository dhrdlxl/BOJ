import java.util.*;

public class BOJ_1201 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();
        sc.close();

        if(N < M + K - 1 || M * K < N)
        {
            System.out.println(-1);
            return;
        }

        int[] answer = new int[N];
        for(int num = 1; num <= N; num++)
        {
            answer[num - 1] = num;
        }
        ArrayList<Integer> startPoints = new ArrayList<>();
        startPoints.add(0);
        startPoints.add(K);
        N -= K;
        M--;
        
        int groupSize = (M == 0 ? 1 : N / M);
        int additional = (M == 0 ? 0 : N % M);

        for(int index = 0; index < M; index++)
        {
            int before = startPoints.get(startPoints.size() - 1);
            startPoints.add(before + groupSize + (additional > 0 ? 1 : 0));
            if(additional > 0)
                additional--;
        }

        for(int index = 0; index < startPoints.size() - 1; index++)
        {
            int begin = startPoints.get(index);
            int end = startPoints.get(index + 1) - 1;
            while(begin < end)
            {
                swap(answer, begin, end);
                begin++;
                end--;
            }
        }

        for(int index = 0; index < answer.length; index++)
        {
            System.out.print(answer[index] + " ");
        }
        return;
    }
    public static void swap(int[] answer, int a, int b)
    {
        int temp = answer[a];
        answer[a] = answer[b];
        answer[b] = temp;
    }
}