import java.util.*;

public class BOJ_1918 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String Equation = sc.nextLine();
        sc.close();

        StringBuilder sb = new StringBuilder();
        Stack<Character> st = new Stack<>();
        for(char expression : Equation.toCharArray())
        {
            if(expression >= 'A' && expression <= 'Z')
            {
                sb.append(expression);
            }
            else if(expression == '(')
            {
                st.push(expression);
            }
            else if(expression == ')')
            {
                while(st.peek() != '(')
                {
                    sb.append(st.pop());
                }
                st.pop();// '('
            }
            else
            {
                if(expression == '+' || expression == '-')
                {
                    while(!st.empty() && (st.peek() == '+' || st.peek() == '-' || st.peek() == '*' || st.peek() == '/'))
                    {
                        sb.append(st.pop());
                    }
                    st.push(expression);
                }
                else
                {
                    while(!st.empty() && (st.peek() == '*' || st.peek() == '/'))
                    {
                        sb.append(st.pop());
                    }
                    st.push(expression);
                }
            }
        }
        while(!st.empty())
        {
            sb.append(st.pop());
        }

        System.out.println(sb.toString());
    }    
}