#include<iostream>
#include<string>
using namespace std;

template<typename T>
class queue
{
private:
    T index[10000];
    int begin, end;

public:
    queue():begin(0),end(0){}
    void push(T x)
    {
        index[end]=x;
        end++;
    }
    int empty()
    {
        if(begin==end)
            return 1;
        return 0;
    }
    T pop()
    {
        if(empty()) return -1;//error 발생 가능
        return index[begin++];
    }
    int size()
    {
        return end-begin;
    }
    T front()
    {
        if(empty()) return -1;
        return index[begin];
    }
    T back()
    {
        if(empty()) return -1;
        return index[end-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    string instruction;
    int num;
    queue<int> q;
    while(N--)
    {
        cin>>instruction;
        if(instruction=="push")
        {
            cin>>num;
            q.push(num);
        }
        else if(instruction=="pop")
        {
            cout<<q.pop()<<'\n';
        }
        else if(instruction=="size")
        {
            cout<<q.size()<<'\n';
        }
        else if(instruction=="empty")
        {
            cout<<q.empty()<<'\n';
        }
        else if(instruction=="front")
        {
            cout<<q.front()<<'\n';
        }
        else if(instruction=="back")
        {
            cout<<q.back()<<'\n';
        }
    }
    return 0;
}