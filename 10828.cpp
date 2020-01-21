#include<iostream>
#include<string>
using namespace std;
class stack{
private:
    int array[10001];
    int index;
public:
    stack():index(0){}
    
    void push(int num)
    {
        array[index]=num;
        index++;
        return;
    }
    int pop()
    {
        if(empty())return -1;
        index--;
        return array[index];
    }
    int size()
    {
        return index;
    }
    bool empty()
    {
        if(index==0) return true;
        return false;
    }
    int top()
    {
        if(empty())return -1;
        return array[index-1];
    }
    
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Z;
    string instruction;
    stack st;
    cin>>N;
    while(N--)
    {
        cin>>instruction;
        if(instruction=="push")
        {
            cin>>Z;
            st.push(Z);
        }
        else if(instruction=="pop")
        {
            cout<<st.pop()<<'\n';
        }
        else if(instruction=="size")
        {
            cout<<st.size()<<'\n';
        }
        else if(instruction=="empty")
        {
            cout<<st.empty()<<'\n';
        }
        else if(instruction=="top")
        {
            cout<<st.top()<<'\n';
        }
    }
    return 0;
}