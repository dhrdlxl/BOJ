#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack<int> index;
    int answer=0;
    string s;

    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            index.push(i);
        }
        else if(s[i]==')')
        {
            if(i-index.top()==1)
            {
                index.pop();
                answer+=index.size();
            }
            else
            {
                index.pop();
                answer++;
            }
        }
    }
    cout<<answer;
    return 0;
}