#include<iostream>
#include<string>
using namespace std;
const int MAX=10001;
template<typename T>
class deque{
    private:
    T array[MAX];
    int begin;
    int end;
    
    public:
    deque():begin(0),end(0){}
    bool empty()
    {
        if(begin==end)return true;
        return false;
    }
    void push_front(T X)
    {
        begin=(begin-1+MAX)%MAX;
        array[begin]=X;
    }
    void push_back(T X)
    {
        array[end]=X;
        end=(end+1)%MAX;
    }
    T pop_front()
    {
        if(empty())return -1;
        T tmp = array[begin];
        begin=(begin+1)%MAX;
        return tmp;
    }
    T pop_back()
    {
        if(empty())return -1;
        end=(end-1+MAX)%MAX;
        return array[end];
    }
    int size()
    {
        return ((end-begin+MAX)%MAX);
    }
    T front()
    {
        if(empty())return -1;
        return array[begin];
    }
    T back()
    {
        if(empty())return -1;
        return array[(end-1+MAX)%MAX];
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    short N;
    string instruction;
    int num;
    deque<int> dq;

    cin>>N;
    while(N--)
    {    
        cin>>instruction;
        if(instruction=="push_front")
        {
            cin>>num;
            dq.push_front(num);
        }
        else if(instruction=="push_back")
        {
            cin>>num;
            dq.push_back(num);
        }
        else if(instruction=="pop_front")
        {
            cout<<dq.pop_front()<<'\n';
        }
        else if(instruction=="pop_back")
        {
            cout<<dq.pop_back()<<'\n';
        }
        else if(instruction=="size")
        {
            cout<<dq.size()<<'\n';
        }
        else if(instruction=="empty")
        {
            if(dq.empty())cout<<"1\n";
            else cout<<"0\n";
        }
        else if(instruction=="front")
        {
            cout<<dq.front()<<'\n';
        }
        else if(instruction=="back")
        {
            cout<<dq.back()<<'\n';
        }
    }
    return 0;
}