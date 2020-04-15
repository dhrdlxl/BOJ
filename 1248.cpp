#include<iostream>
using namespace std;

int text[10][10];
int ans[10];
int N;
bool check(int index){
    int sum=0;
    for(int i=0;i<=index;i++)
    {
        sum+=ans[i];
    }
    
    for(int i=0;i<=index;i++)
    {
        if(text[i][index]==0 && sum!=0) return false;
        else if(text[i][index]==-1 && sum>=0) return false;
        else if(text[i][index]==1 && sum<=0) return false;
        sum-=ans[i];
    }
    return true;
}
bool recursive(int index)
{
    if(index==N)
    {
        return true;
    }
    if(text[index][index]==0)
    {
        ans[index]=0;
        if(recursive(index+1))
            return true;
        else
            return false;
    }

    for(int i=1;i<=10;i++)
    {
        ans[index]=i*text[index][index];//text[index][index] ´Â 1 ¶Ç´Â -1
        if(check(index))
            if(recursive(index+1)) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;

    char ch;
    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            cin>>ch;
            if(ch=='0')text[i][j]=0;
            else if(ch=='-')text[i][j]=-1;
            else if(ch=='+')text[i][j]=1;
        }
    }

    recursive(0);
    
    for(int i=0;i<N;i++)
        cout<<ans[i]<<' ';
    return 0;
}