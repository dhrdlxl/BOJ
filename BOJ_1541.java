import java.util.*;
import java.io.*;

public class BOJ_1541 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Queue<String> q = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        String line = br.readLine();
       
        for(char character : line.toCharArray())
        {
            if(character == '-')
            {
                if(sb.length() > 0)
                {
                    q.offer(sb.toString());
                }
                
                sb = new StringBuilder();
                q.offer("-");
            }
            else if(character == '+')
            {
                if(sb.length() > 0)
                {
                    q.offer(sb.toString());
                }
                sb = new StringBuilder();
                q.offer("+");
            }
            else//number
            {
                sb.append(character);
            }
        }
        q.offer(sb.toString());

        Stack<String> st = new Stack<>();
        int end = q.size();
        for(int index = 0; index < end; index++)
        {
            String now = q.poll();
            if(now.equals("+"))
            {
                String before = st.pop();
                String next = q.poll();
                st.push(Integer.toString(Integer.parseInt(before) + Integer.parseInt(next)));
                index++;
            }
            else
            {
                st.push(now);
            }
        }

        int answer = 0;
        sb = new StringBuilder();
        while(!st.isEmpty())
        {
            String now = st.pop();
            if(now.equals("-"))
            {
                sb.insert(0, "-");
                answer += Integer.parseInt(sb.toString());
                sb = new StringBuilder();
            }
            else
            {
                sb.append(now);
            }
        }

        if(sb.length() > 0)
        {
            answer += Integer.parseInt(sb.toString());
        }

        System.out.println(answer);
        return;
    }    
}