import java.util.*;

public class BOJ_11729 {
    private static StringBuffer sb;
    private static int count;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.close();

        sb = new StringBuffer();
        hanoi(N, 1, 3, 2);
        sb.insert(0, Integer.toString(count) + "\n");

        System.out.print(sb.toString());
    }

    private static void hanoi(int N, int from, int to, int via)
    {
        if(N == 1)
        {
            sb.append(Integer.toString(from) + " " + Integer.toString(to) + "\n");
            count++;
            return;
        }
        
        hanoi(N-1, from, via, to);
        sb.append(Integer.toString(from) + " " + Integer.toString(to) + "\n");
        count++;
        hanoi(N-1, via, to, from);
    }
}