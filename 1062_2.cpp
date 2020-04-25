#include<iostream>
#include<string>
using namespace std;

int mask[50];
int max(int a,int b)
{
    return a>b? a:b;
}

int check(int bitMask,int N)
{
    int count=0;
    for(int i=0;i<N;i++)
    {
        if((bitMask&mask[i])==mask[i])
        {
            count++;
        }
    }
    return count;
}

int go(int index,int K,int bitMask,int N)
{
    int answer=0;
    if(K<0) return 0;
    if(index=='z'-'a'+1)
    {
        return check(bitMask,N);
    }

    //알파벳을 배울 때
    answer=max(answer,go(index+1,K-1,bitMask|(1<<index),N));

    //알파벳을 배우지 않을 때
    if(index!='a'-'a' && index!='n'-'a' && index!='t'-'a' && 
    index!='i'-'a' && index!='c'-'a')
    {
        answer=max(answer,go(index+1,K,bitMask,N));
    }

    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin>>N>>K;

    string s;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            mask[i]|=(1<<(s[j]-'a'));
        }
    }

    cout<<go(0,K,0,N);
    return 0;
}