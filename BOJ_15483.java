import java.io.*;

public class BOJ_15483 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String A = br.readLine();
        String B = br.readLine();
        int[][] editDistance = new int[A.length() + 1][B.length() + 1];

        for(int row = 0; row <= A.length(); row++)
            editDistance[row][0] = row;
        
        for(int col = 0; col <= B.length(); col++)
            editDistance[0][col] = col;
        
        for(int row = 1; row <= A.length(); row++)
        {
            for(int col = 1; col<= B.length(); col++)
            {
                if(A.charAt(row - 1) == B.charAt(col - 1))
                {
                    editDistance[row][col] = editDistance[row - 1][col - 1];
                }
                else
                {
                    int minValue = editDistance[row - 1][col - 1];
                    minValue = min(minValue, editDistance[row - 1][col]);
                    minValue = min(minValue, editDistance[row][col - 1]);
                    editDistance[row][col] = minValue + 1;
                }
            }
        }

        System.out.println(editDistance[A.length()][B.length()]);
        return;
    }
    private static int min(int a, int b)
    {
        return  a <= b ? a : b;
    }
}