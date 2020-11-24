import java.util.*;

public class BOJ_12970 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        sc.close();

        int countA = N / 2;
        int countB = N - countA;
        if(countA * countB < K)
        {
            System.out.println(-1);
            return;
        }

        int totalMoveA = countA * countB - K;
        int unUsedA = totalMoveA / countB;
        int oneMoveA = totalMoveA % countB;
        int notMovedA = countA - unUsedA;
        if(oneMoveA != 0)
            notMovedA--;
        
        StringBuilder sb = new StringBuilder();
        for(int index = 0; index < notMovedA; index++)
        {
            sb.append('A');
        }
        for(int index = 1; index <= countB; index++)
        {
            sb.append('B');
            if(index == oneMoveA)
            {
                sb.append('A');
            }
        }
        for(int index = 0; index < unUsedA; index++)
        {
            sb.append('A');
        }
        
        System.out.println(sb.toString());
        return;
    }    
}