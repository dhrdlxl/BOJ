#include<iostream>
#include<string>
using namespace std;

int k;
long long Min=9999999999;
long long Max=0;
char signs[9];
string answer_Min;
string answer_Max;
void recursive(int count, long long num,int bitmask)
{
    if(count==k+1)
    {
        if(num>Max)Max=num;
        if(num<Min)Min=num;
        return;
    }
    for(int i=0;i<10;i++)
    {
        if((bitmask&(1<<i))==0)
        {
            if(count!=0)
            {
                if((signs[count-1]=='>' && num%10<i) || (signs[count-1]=='<' && num%10>i))
                {
                    continue;
                }
            }
            recursive(count+1,num*10+i,bitmask|(1<<i));
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>k;
    for(int i=0;i<k;i++)
        cin>>signs[i];
        
    recursive(0,0,0);
    do{
        answer_Min+=Min%10+'0';
        Min/=10;
    }while(Min>0);
    do{
        answer_Max+=Max%10+'0';
        Max/=10;
    }while(Max>0);

    if(answer_Min.size()<k+1)answer_Min+='0';
    if(answer_Max.size()<k+1)answer_Max+='0';
    
    for(int i=k;i>=0;i--)
    {
        cout<<answer_Max[i];
    }
    cout<<'\n';
    for(int i=k;i>=0;i--)
    {
        cout<<answer_Min[i];
    }
    return 0;
}