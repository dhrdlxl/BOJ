import java.util.*;
import java.io.*;

public class BOJ_5585 {
    private static final int[] changes = new int[]{500, 100, 50, 10, 5, 1};
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int cost = sc.nextInt();
        sc.close();

        int restMoney = 1000 - cost;
        int answer = 0;

        for(int change : changes)
        {
            int div = restMoney / change;
            answer += div;
            restMoney -= (div * change);
        }

        System.out.println(answer);

        return;
    }
}