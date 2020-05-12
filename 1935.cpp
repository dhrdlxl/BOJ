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
    
    int N;//�ǿ������� ����
    int operand[27];//�ǿ����� ���� �迭
    double answer=0;
    char str[101];//����
    
    cin>>N;
    cin.ignore();//cin�� �ϸ� buffer�� ���Ͱ� ���������Ƿ� ����ش�.
    cin.getline(str,101,'\n');

    
    for(int i=0;i<N;i++)
    {
        cin>>operand[i];
    }

    stack st;
    double left,right;//���� �ǿ�����, ������ �ǿ�����
    for(int i=0;str[i]!=NULL;i++)//���ڿ��� ��
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
    cout<<fixed;//�Ҽ����� ǥ��(���� �� ���� ��ü ǥ��)
    //���� ��ü ǥ�� �ϰ� ���� �� cout.unsetf(ios::fixed); ���
    cout.precision(2);//�Ҽ��� 2°�ڸ� ���� ǥ��
    cout<<answer;
    
    return 0;
}