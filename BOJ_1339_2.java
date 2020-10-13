import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_1339_2 {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] alphabet = new int['Z' - 'A' + 1];
        
        for(int index = 0; index < N; index++)
        {
            String word = br.readLine();
            long numberOfDigits = 1;
            for(int alphabetIndex = word.length() - 1; alphabetIndex >= 0; alphabetIndex--)
            {
                alphabet[word.charAt(alphabetIndex) - 'A'] += numberOfDigits;
                numberOfDigits *= 10;
            }
        }
        Arrays.sort(alphabet);//오름차순

        int num = 9;
        int answer = 0;
        for(int index = alphabet.length - 1; index >= 0; index--)
        {
            int alphabetSum = alphabet[index];
            if(alphabetSum == 0)
                break;
            answer += num * alphabetSum;
            num--;
        }

        System.out.println(answer);
    }
}
