import java.util.*;

public class BOJ_12919 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        String T = sc.nextLine();
        sc.close();

        if(dfs(S, T))
            System.out.println(1);
        else
            System.out.println(0);
    }

    public static boolean dfs(String S, String T)
    {
        if(S.length() == T.length())
        {
            if(S.equals(T))
            {
                return true;
            }
            return false;
        }

        if(T.charAt(T.length() - 1) == 'A')
        {
            StringBuilder copyT = new StringBuilder(T);
            copyT.deleteCharAt(T.length() - 1);
            if(dfs(S, copyT.toString()))
            {
                return true;
            }
        }
        
        if(T.charAt(0) == 'B')
        {
            StringBuilder copyT = new StringBuilder(T);
            copyT.deleteCharAt(0);
            copyT.reverse();
            if(dfs(S, copyT.toString()))
            {
                return true;
            }
        }

        return false;
    }
}