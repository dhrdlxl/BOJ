import java.util.Scanner;

public class BOJ_9663_2 {
    private static boolean[] rightUpDiagonal;
    private static boolean[] rightDownDiagonal;
    private static boolean[] cols;
    private static int N;
    private static int answer = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        scanner.close();

        rightUpDiagonal = new boolean[N * 2 + 1];
        rightDownDiagonal = new boolean[N * 2 + 1];
        cols = new boolean[N];

        findQueen(0);

        System.out.println(answer);
    }

    private static void findQueen(int y)
    {
        if(N == y)
        {
            answer++;
            return;
        }
        
        for(int col = 0; col < N; col++)
        {
            if(rightUpDiagonal[y + col] == false && rightDownDiagonal[col - y + N - 1] == false && cols[col] == false)
            {
                rightUpDiagonal[y + col] = true;
                rightDownDiagonal[col - y + N - 1] = true;
                cols[col] = true;
                
                findQueen(y + 1);
                
                rightUpDiagonal[y + col] = false;
                rightDownDiagonal[col - y + N - 1] = false;
                cols[col] = false;
            }
        }

        return;
    }
}
