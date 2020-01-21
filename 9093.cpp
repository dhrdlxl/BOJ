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
cin�� ����, ����, ���� ������ �� �������� �Է����� �ް� ���ۿ� �����Ѵ�.
���� �Է� ���ۿ� ����, ����, ���� ����ǹǷ� 
cin.ignore()�� �Է� ���۸� ���� ���� �Է��� �޾ƾ� �Ѵ�.
* cin�� ���ۿ� ����, ����, ���� �־ �����Ѵ�.
* scanf�� cin�� ����.

getline()�� ���� ���������� �ϳ��� �Է����� �ް� ���ۿ� ���͸� ������ �ʴ´�.
* getline()�� ���ۿ� ���Ͱ� ������ �������� �ʰ� ��´�.
-> �Է��� "a\nb" �� ��, cin �� getline �� getline�� ���ۿ� �ִ� \n�� ��´�.
*/