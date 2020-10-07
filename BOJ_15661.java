import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_15661 {
    private static final int INF = 987654321;
    private static int answer = INF;
    private static int N;
    private static int[][] board;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        board = new int[N][N];

        for(int row = 0; row < N; row++)
        {
            st = new StringTokenizer(br.readLine());    
            for(int col = 0; col < N; col++)
            {
                board[row][col] = Integer.parseInt(st.nextToken());
            }
        }

        ArrayList<Integer> team1 = new ArrayList<>();
        ArrayList<Integer> team2 = new ArrayList<>();
    
        simulation(team1, team2, 0);

        bw.write(Integer.toString(answer));
        bw.flush();
        bw.close();
        return;
    }

    private static void simulation(ArrayList<Integer> team1, ArrayList<Integer> team2, int player)
    {
        if(player == N)
        {
            int abilityTeam1 = 0;
            int abilityTeam2 = 0;

            for(int i = 0; i < team1.size(); i++)
            {
                int iPlayer = team1.get(i);
                for(int j = i + 1; j < team1.size(); j++)
                {
                    int jPlayer = team1.get(j);
                    abilityTeam1 += board[iPlayer][jPlayer];
                    abilityTeam1 += board[jPlayer][iPlayer];
                }
            }

            for(int i = 0; i < team2.size(); i++)
            {
                int iPlayer = team2.get(i);
                for(int j = i + 1; j < team2.size(); j++)
                {
                    int jPlayer = team2.get(j);
                    abilityTeam2 += board[iPlayer][jPlayer];
                    abilityTeam2 += board[jPlayer][iPlayer];
                }
            }

            int abilityDifference = abilityTeam1 - abilityTeam2;
            if(abilityDifference < 0) 
                abilityDifference *= -1;
            if(answer > abilityDifference)
                answer = abilityDifference;
            return;
        }

        team1.add(player);
        simulation(team1, team2, player + 1);
        team1.remove(team1.size() - 1);

        team2.add(player);
        simulation(team1, team2, player + 1);
        team2.remove(team2.size() - 1);

        return;
    }
}
