#include<iostream>
#include<stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int M;
    char instruction;
    stack<char> left,right;
    
    cin>>str;
    cin>>M;
    for(int i=0;i<str.size();i++)left.push(str[i]);

    while(M--)
    {
        cin>>instruction;
        if(instruction=='L' && !left.empty())
        {
            right.push(left.top());
            left.pop();
        }
        else if(instruction=='D' && !right.empty())
        {
            left.push(right.top());
            right.pop();
        }
        else if(instruction=='B' && !left.empty())
        {
            left.pop();
        }
        else if(instruction=='P')
        {
            char alphabet;
            cin>>alphabet;
            left.push(alphabet);
        }
    }
    while(!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
    while(!right.empty())
    {
        cout<<right.top();
        right.pop();
    }
    return 0;
}