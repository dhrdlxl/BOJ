//사용 가능한 숫자를 먼저 색출한 후 답을 구하는 방법.
//즉, num 배열의 값이 -1이 아닌 수들로 만들 수 있는 모든 경우를 본다.
#include<iostream>
using namespace std;
int num[10];
int N,M;
int recursive(int push,int channel,int count,int min)
{
    if(count>0)
    {
        int x=N-channel;
        if(x<0)x*=-1;
        if(min>x+count)
            min=x+count;
    }
 
    if(count==push+1)
    {
        return min;
    }
    for(int i=0;i<10;i++)
    {
        if(num[i]!=-1)
        {
            min=recursive(push,channel*10+i,count+1,min);
        }
    }
    return min;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int answer=0;
    int now=100;
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        int a;
        cin>>a;
        num[a]=-1;
    }

    int nCopy=N;
    int push=0;
    do
    {
        push++;
        nCopy/=10;
    }while(nCopy>0);
    
    int min=N-now;
    if(min<0)min*=-1;
    
    answer=recursive(push,0,0,min);

    cout<<answer;
    return 0;
}