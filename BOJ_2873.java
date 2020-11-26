import java.io.*;
import java.util.*;

public class BOJ_2873 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        int[][] board = new int[R][C];
        for(int row = 0; row < R; row++)
        {
            st = new StringTokenizer(br.readLine());
            for(int col = 0; col < C; col++)
            {
                board[row][col] = Integer.parseInt(st.nextToken());
            }
        }

        StringBuilder answer = new StringBuilder();
        if(C % 2 == 1)
        {
            for(int col = 0; col < C; col++)
            {
                for(int row = 0; row < R - 1; row++)
                {
                    if(col % 2 == 0)
                        answer.append('D');
                    else
                        answer.append('U');
                }

                if(col < C - 1)
                    answer.append('R');
            }
        }
        else if(R % 2 == 1)
        {
            for(int row = 0; row < R; row++)
            {
                for(int col = 0; col < C - 1; col++)
                {
                    if(row % 2 == 0)
                        answer.append('R');
                    else
                        answer.append('L');
                }

                if(row < R - 1)
                    answer.append('D');
            }
        }
        else
        {
            int minY = 0;
            int minX = 1;
            for(int row = 0; row < R; row++)
            {
                for(int col = 0; col < C; col++)
                {
                    if((row + col) % 2 == 1 && board[row][col] < board[minY][minX])
                    {
                        minY = row;
                        minX = col;
                    }
                }
            }

            int beginY = 0;
            int beginX = 0;
            int endY = R - 1;
            int endX = C - 1;
            StringBuilder endMove = new StringBuilder();
            
            while(endY - beginY > 1)
            {
                if(beginY / 2 < minY / 2)
                {
                    for(int row = 0; row < 2; row++)
                    {
                        for(int col = 0; col < C - 1; col++)
                        {
                            if(row % 2 == 0)
                                answer.append('R');
                            else
                                answer.append('L');
                        }
                        answer.append('D');
                    }
                    beginY += 2;
                }

                if(minY / 2 < endY / 2)
                {
                    for(int row = 0; row < 2; row++)
                    {
                        for(int col = 0; col < C - 1; col++)
                        {
                            if(row % 2 == 0)
                                endMove.append('R');
                            else
                                endMove.append('L');
                        }
                        endMove.append('D');
                    }
                    endY -= 2;
                }
            }

            while(endX - beginX > 1)
            {
                if(beginX / 2 < minX / 2)
                {
                    answer.append("DRUR");
                    beginX += 2;
                }

                if(minX / 2 < endX / 2)
                {
                    endMove.append("DRUR");
                    endX -= 2;
                }
            }

            if(beginY == minY)
            {
                answer.append("DR");
            }
            else if(beginX == minX)
            {
                answer.append("RD");
            }

            answer.append(endMove.reverse());
        }

        System.out.println(answer.toString());
        
        return;
    }
}