import java.io.*;

public class BOJ_12904 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        String T = br.readLine();
        br.close();

        StringBuilder sb = new StringBuilder(T);

        while(S.length() < sb.length())
        {
            int index = sb.length() - 1;
            if(sb.charAt(index) == 'A')
            {
                sb.deleteCharAt(index);
            }
            else if(sb.charAt(index) == 'B')
            {
                sb.deleteCharAt(index);
                sb.reverse();
            }
        }

        if(S.equals(sb.toString()))
        {
            System.out.println(1);
        }
        else
        {
            System.out.println(0);
        }
    }    
}