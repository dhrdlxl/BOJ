//1~1,000,000 �� ��ȸ�ϸ� �Ұ����� ���� �����ϰ� �ּڰ��� ã�� ���
#include<iostream>
using namespace std;

int N,M;
bool num[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    
    for(int i=0;i<M;i++)
    {
        int x;
        cin>>x;
        num[x]=true;
    }

    int answer=100-N;
    if(answer<0)answer*=-1;

    for(int i=0;i<1000000;i++)
    {
        int x=i;
        int count=0;
        do{
            count++;
            if(num[x%10]==true)
            {
                count=0;
                break;
            }
            x/=10;
        }while(x>0);
        if(count>0)
        {
            int guess=N-i;
            if(guess<0)guess*=-1;
            guess+=count;//��ư ���� Ƚ���� ���Ѵ�.
            if(guess<answer)answer=guess;
        }
    }
    
    cout<<answer;
    return 0;
}