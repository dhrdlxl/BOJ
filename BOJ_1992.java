import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ_1992 {
    private static int[][] board;
    private static BufferedWriter bw;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        board = new int[N][N];

        for (int row = 0; row < N; row++) {
            String s = br.readLine();
            for (int col = 0; col < s.length(); col++) {
                board[row][col] = s.charAt(col) - '0';
            }
        }

        compress(new Pos(0, 0), N);

        bw.flush();
        bw.close();
        return;
    }

    private static void compress(Pos startPos, int length) throws IOException {
        int y = startPos.y;
        int x = startPos.x;
        int countOne = 0;
        for(int row = y; row < y + length; row++)
        {
            for(int col = x; col < x + length; col++)
            {
                countOne += board[row][col];
            }
        }
        if(countOne == 0)
        {
            bw.write("0");
        }
        else if(countOne == length * length)
        {
            bw.write("1");
        }
        else
        {
            bw.write("(");
            int divideLength = length / 2;
            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < 2; j++)
                {
                    compress(new Pos(startPos.y + divideLength * i, startPos.x + divideLength * j), divideLength);
                }
            }
            bw.write(")");
        }
        return;
    }

    private static class Pos {
        public int y;
        public int x;
    
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }    
}
