#include<iostream>
#include<deque>
#include<queue>
#include<string>
using namespace std;

int max(int a,int b){return a>b?a:b;}
int cal(int leftOperand,int rightOperand, char oper)
{
    int ans=0;

    if(oper=='+')
    {
        ans = leftOperand+rightOperand;
    }
    else if(oper=='-')
    {
        ans = leftOperand-rightOperand;
    }
    else if(oper=='*')
    {
        ans = leftOperand*rightOperand;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string equation;
    
    cin>>N>>equation;

    int operatorSize = (N-1)/2;
    int answer=(1<<31)+1;
    for(int i=0;i<(1<<operatorSize);i++)
    {
        deque<int> nums;
        queue<char> operators;
        int opIndex=0;
        int result=0;
        bool checkContinue=false;
        for(int j=0;j<equation.size();j++)
        {
            if('0'<=equation[j] && equation[j]<='9')//number
            {
                nums.push_back(equation[j]-'0');
            }
            else//operator
            {
                if((i&(1<<opIndex))!=0 && !checkContinue)//Priority operation
                {
                    int leftOperand=nums.back();
                    int rightOperand=equation[++j]-'0';
                    nums.pop_back();
                    nums.push_back(cal(leftOperand,rightOperand,equation[j-1]));\
                    checkContinue=true;
                }
                else
                {
                    operators.push(equation[j]);
                    checkContinue=false;
                }
                opIndex++;
            }
        }
        result=nums.front();
        nums.pop_front();
        while(!operators.empty())
        {
            result=cal(result,nums.front(),operators.front());
            nums.pop_front();
            operators.pop();
        }
        answer=max(answer,result);
    }

    cout<<answer;
    return 0;
}