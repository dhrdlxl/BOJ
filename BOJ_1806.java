import java.util.*;
import java.io.*;

class BOJ_1806 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int[] sequence = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int index = 0; index < N; index++) {
            sequence[index] = Integer.parseInt(st.nextToken());
        }

        int answer = solution(sequence, S);

        System.out.println(answer);
    }

    private static int solution(int[] sequence, int S) {
        int left = 0;
        int right = 0;
        int sum = sequence[0];
        int answer = sequence.length + 1;

        while (right < sequence.length) {
            if (sum < S) {
                right++;
                if (right < sequence.length) {
                    sum += sequence[right];
                }
            } else if (sum >= S) {
                answer = min(answer, right - left + 1);
                sum -= sequence[left];
                left++;
            }
        }

        return answer < sequence.length + 1 ? answer : 0;
    }

    private static int min(int a, int b) {
        return a <= b ? a : b;
    }
}