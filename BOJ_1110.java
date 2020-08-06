import java.util.Scanner;
public class BOJ_1110 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int target = sc.nextInt();
        sc.close();
        int answer = 0;
        int num = -1;
        int copyTarget = target;
        while(target != num)
        {
            answer++;
            num = (copyTarget / 10 + copyTarget % 10) % 10 + (copyTarget % 10) * 10;
            copyTarget = num;
        }

        System.out.println(answer);   
    }
}