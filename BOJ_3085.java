import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ_3085 {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        char[][] board = new char[N][N];

        for(int row = 0; row < N; row++)
        {
            String s = br.readLine();
            for(int col = 0; col < N; col++)
            {
                board[row][col] = s.charAt(col);
            }
        }

        int answer = 1;

        
        int count = 1;
        //가로
        for(int row = 0; row < N; row++)
        {
            count = 1;
            for(int col = 0; col < N - 1; col++)
            {
                if(board[row][col] == board[row][col + 1])
                {
                    count++;
                    if(count > answer)
                        answer = count;
                    continue;
                }
                count = 1;
                swap(board, row, col, row, col + 1);

                int count1 = 1;
                for(int m_col = 0; m_col < N - 1; m_col++)
                {
                    if(board[row][m_col] == board[row][m_col + 1])
                    {
                        count1++;
                        if(count1 > answer)
                            answer = count1;
                    }
                    else
                        count1 = 1;
                }
                count1 = 1;
                int count2 = 1;
                for(int m_row = 0; m_row < N - 1; m_row++)
                {
                    if(board[m_row][col] == board[m_row + 1][col])
                    {
                        count1++;
                        if(count1 > answer)
                            answer = count1;
                    }
                    else
                        count1 = 1;

                    if(board[m_row][col + 1] == board[m_row + 1][col + 1])
                    {
                        count2++;
                        if(count2 > answer)
                            answer = count2;
                    }
                    else
                        count2 = 1;
                }
                
                swap(board, row, col, row, col + 1);
            }
        }

        //세로
        for(int col = 0; col < N; col++)
        {
            count = 1;
            for(int row = 0; row < N - 1; row++)
            {
                if(board[row][col] == board[row + 1][col])
                {
                    count++;
                    if(count > answer)
                        answer = count;
                    continue;
                }
                count = 1;
                
                swap(board, row, col, row + 1, col);

                int count1 = 1;
                int count2 = 1;
                for(int m_col = 0; m_col < N - 1; m_col++)
                {
                    if(board[row][m_col] == board[row][m_col + 1])
                    {
                        count1++;
                        if(count1 > answer)
                            answer = count1;
                    }
                    else
                        count1 = 1;
                    
                    if(board[row + 1][m_col] == board[row + 1][m_col + 1])
                    {
                        count2++;
                        if(count2 > answer)
                            answer = count2;
                    }
                    else
                        count2 = 1;
                }
                count1 = 1;
                
                for(int m_row = 0; m_row < N - 1; m_row++)
                {
                    if(board[m_row][col] == board[m_row + 1][col])
                    {
                        count1++;
                        if(count1 > answer)
                            answer = count1;
                    }
                    else
                        count1 = 1;
                }
                
                swap(board, row, col, row + 1, col);
            }
        }

        bw.write(Integer.toString(answer));
        bw.flush();
        bw.close();
        return;
    }

    public static void swap(char[][] board, int y1, int x1, int y2, int x2)
    {
        char temp = board[y1][x1];
        board[y1][x1] = board[y2][x2];
        board[y2][x2] = temp;
    }
}