#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcd(int a,int b)
{
    return a*b/gcd(a,b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M,N,x,y,test_case;
    cin>>test_case;
    while(test_case--)
    {
        cin>>M>>N>>x>>y;
        x--;
        y--;
        bool check=true;
        int LCD = lcd(N,M);
        for(int i=0;x+M*i<LCD;i++)
        {
            if((x+M*i)%N==y)
            {
                cout<<x+M*i+1<<'\n';
                check=false;
                break;
            }
        }
        if(check)
            cout<<-1<<'\n';
    }
    
    return 0;
}