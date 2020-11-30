import java.io.*;

public class BOJ_10988 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String text = br.readLine();

        int begin = 0;
        int end = text.length() - 1;

        while(begin < end)
        {
            if(text.charAt(begin) != text.charAt(end))
            {
                System.out.println(0);
                return;
            }
            begin++;
            end--;
        }

        System.out.println(1);
    }
}