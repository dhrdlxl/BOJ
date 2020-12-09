import java.util.*;
import java.io.*;

public class BOJ_1935 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        String Equation = br.readLine();
        double[] valueTable = new double[N];
        for(int index = 0; index < N; index++)
        {
            valueTable[index] = Double.parseDouble(br.readLine());
        }

        Stack<Double> st = new Stack<>();
        for(char expression : Equation.toCharArray())
        {
            if(expression >= 'A' && expression <= 'Z')
            {
                st.push(valueTable[expression - 'A']);
            }
            else
            {
                double second = st.pop();
                double first = st.pop();

                if(expression == '+')
                {
                    st.push(first + second);
                }
                else if(expression == '-')
                {
                    st.push(first - second);
                }
                else if(expression == '*')
                {
                    st.push(first * second);
                }
                else
                {
                    st.push(first / second);
                }
            }
        }

        double answer = st.pop();
        System.out.println(String.format("%.2f", answer));
    }
}