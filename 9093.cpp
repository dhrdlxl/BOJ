#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    cin.ignore();

    string sentence;
    stack<char> st;
    while(T--)
    {
        getline(cin,sentence);
        sentence+='\n';
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' ' || sentence[i]=='\n')
            {
                while(!st.empty())
                {
                    cout<<st.top();
                    st.pop();
                }
                cout<<sentence[i];
            }
            else
            {
                st.push(sentence[i]);
            }
        }
    }
    return 0;
}

/*
cin은 띄어쓰기, 엔터, 탭이 나오면 그 전까지를 입력으로 받고 버퍼에 저장한다.
따라서 입력 버퍼에 띄어쓰기, 엔터, 탭이 저장되므로 
cin.ignore()로 입력 버퍼를 비우고 이후 입력을 받아야 한다.
* cin은 버퍼에 띄어쓰기, 엔터, 탭이 있어도 무시한다.
* scanf도 cin과 같다.

getline()은 엔터 직전까지를 하나의 입력으로 받고 버퍼에 엔터를 남기지 않는다.
* getline()은 버퍼에 엔터가 있으면 무시하지 않고 잡는다.
-> 입력이 "a\nb" 일 때, cin 후 getline 시 getline이 버퍼에 있는 \n을 잡는다.
*/