#include<iostream>
using namespace std;

class stack{
private:
    double arr[30];
    int index;
public:
    stack():index(0){}

    bool isEmpty()
    {
        return index==0? true:false;
    }
    void push(double x)
    {
        arr[index]=x;
        index++;
    }
    void pop()
    {
        if(!isEmpty()) index--;
        return;
    }
    double top()
    {
        if(!isEmpty())  return arr[index-1];
        return -1;
    }
    int size()
    {
        return index;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;//피연산자의 개수
    int operand[27];//피연산자 매핑 배열
    double answer=0;
    char str[101];//계산식
    
    cin>>N;
    cin.ignore();//cin을 하면 buffer에 엔터가 남아있으므로 비워준다.
    cin.getline(str,101,'\n');

    
    for(int i=0;i<N;i++)
    {
        cin>>operand[i];
    }

    stack st;
    double left,right;//왼쪽 피연산자, 오른쪽 피연산자
    for(int i=0;str[i]!=NULL;i++)//문자열의 끝
    {
        if('A'<=str[i] && str[i]<='Z')
        {
            st.push(operand[str[i]-'A']);
        }
        else//operator
        {
            right=st.top();
            st.pop();
            left=st.top();
            st.pop();
            switch(str[i])
            {
            case '+':
                st.push(left+right);
                break;
            case '-':
                st.push(left-right);
                break;
            case '*':
                st.push(left*right);
                break;
            case '/':
                st.push(left/right);
                break;
            }
        }
    }

    answer=st.top();
    st.pop();
    cout<<fixed;//소수점만 표현(안할 시 정수 전체 표현)
    //정수 전체 표현 하고 싶을 시 cout.unsetf(ios::fixed); 사용
    cout.precision(2);//소수점 2째자리 까지 표현
    cout<<answer;
    
    return 0;
}