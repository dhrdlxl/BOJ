#include<iostream>
#include<stack>
#include<string>

using namespace std;
void stprint(stack<char>& stp)
{
    while(!stp.empty())
    {
        cout<<stp.top();
        stp.pop();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    stack<char> st;
    getline(cin,s);
    s+='\n';
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='<')
        {
            stprint(st);
            while(s[i]!='>')
            {
                cout<<s[i];
                i++;
            }
            cout<<s[i];
        }
        else if(s[i]==' ' || s[i]=='\n')
        {
            stprint(st);
            cout<<s[i];
        }
        else
        {
            st.push(s[i]);
        } 
    }
    return 0;
}