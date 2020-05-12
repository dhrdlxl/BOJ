#include<iostream>
using namespace std;

class stack{
private:
    char arr[100];
    int index;
public:
    stack():index(0){}
    void push(char a)
    {
        arr[index]=a;
        index++;
        return;
    }
    void pop()
    {
        if(!isEmpty())
        {
            index--;
        }
        return;
    }
    bool isEmpty()
    {
        return index==0? true:false;
    }
    char top()
    {
        if(isEmpty())return -1;
        return arr[index-1];
    }
    int size()
    {
        return index;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack st;
    char str[100];
    
    int strSize=0;

    while(cin>>str[strSize++]){}
    
    for(int i=0;i<strSize-1;i++)
    {
        if('A'<=str[i] && str[i]<='Z')
        {
            cout<<str[i];
        }
        else if(str[i]==')')
        {
            while(st.top()!='(')
            {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else if(str[i]=='(')
        {
            st.push(str[i]);
        }
        else if(str[i]=='+' || str[i]=='-')
        {
            while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/')
            {
                cout<<st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        else if(str[i]=='*' || str[i]=='/')
        {
            while(st.top()=='*' || st.top()=='/')
            {
                cout<<st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.isEmpty())
    {
        cout<<st.top();
        st.pop();
    }
    return 0;
}