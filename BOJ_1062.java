import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1062 {
    private static char[] defaultAlphabet = new char[]{'a', 'c', 'i', 'n', 't'};
    private static int answer = 0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int used = 0;
        K -= 5;
        if(K < 0)
        {
            System.out.println(0);
            return;
        }
        for(char alphabet : defaultAlphabet)
        {
            used |= (1 << alphabet - 'a');
        }

        int[] sentences = new int[N];
        for(int index = 0; index < N; index++)
        {
            String line = br.readLine();
            for(int lineIndex = 0; lineIndex < line.length(); lineIndex++)
            {
                sentences[index] |= (1 << (line.charAt(lineIndex) - 'a'));
            }
        }

        go(0, K, sentences, used);

        System.out.println(answer);
        return;
    }

    private static void go(int step, int K, int[] sentences, int used)
    {        
        if(K == 0)
        {
            int count = 0;
            for(int sentence : sentences)
            {
                if((sentence & used) == sentence)
                {
                    count++;
                }
            }
            if(count > answer)
                answer = count;
            
            return;
        }
        if(step == 'z' - 'a' + 1)
            return;

        if((used & (1 << step)) > 0)
        {
            go(step + 1, K, sentences, used);
            return;
        }

        go(step + 1, K, sentences, used);
        go(step + 1, K -1, sentences, used | (1 << step));
        return;
    }
}
