#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    char instruction,alphabet;
    string s;
    list<char> editor;
    list<char>::iterator it;

    cin>>s;
    for(int i=0;i<s.size();i++)
        editor.push_back(s[i]);
    it = editor.end();
    cin>>M;
    while(M--)
    {
        cin>>instruction;
        if(instruction=='L')
        {
            if(it!=editor.begin())it--;
        }
        else if(instruction=='D')
        {
            if(it!=editor.end())it++;
        }
        else if(instruction=='B')
        {
            if(it!=editor.begin())
            {
                it=editor.erase(--it);
            }
        }
        else if(instruction=='P')
        {
            cin>>alphabet;
            editor.insert(it,alphabet);
        }

    }
    for(char answer:editor)
    {
        cout<<answer;
    }
    return 0;
}
