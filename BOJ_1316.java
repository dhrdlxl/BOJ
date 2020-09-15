import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class BOJ_1316 {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        int answer = 0;
        
        String word;
        boolean[] check;
        boolean checkGroup;
        for(int wordIndex = 0 ; wordIndex < N; wordIndex++)
        {
            check = new boolean['z' - 'a' + 1];
            checkGroup = true;

            word = br.readLine();
            for(int index = 0 ; index < word.length(); index++)
            {
                char alphabet = word.charAt(index);
                if(check[alphabet - 'a'] == false)
                {
                    check[alphabet - 'a'] = true;
                }
                else if(alphabet != word.charAt(index -1))
                {
                    checkGroup = false;
                    break;
                }
            }
            if(checkGroup)
                answer++;
        }
        bw.write(Integer.toString(answer));
        bw.flush();
        bw.close();
    }    
}
