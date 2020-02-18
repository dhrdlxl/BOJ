#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin>>M;

    int S=0;
    string Ops;
    int num;
    while(M--)
    {
        cin>>Ops;
        if(Ops=="add")
        {
            cin>>num;
            S|=1<<(num-1);
        }
        else if(Ops=="remove")
        {
            cin>>num;
            S&=~(1<<num-1);
        }
        else if(Ops=="check")
        {
            cin>>num;
            if(S&(1<<num-1))
            {
                cout<<"1\n";
            }
            else
            {
                cout<<"0\n";
            }
            
        }
        else if(Ops=="toggle")
        {
            cin>>num;
            S^=(1<<num-1);
        }
        else if(Ops=="all")
        {
            S=(1<<20)-1;
        }
        else if(Ops=="empty")
        {
            S=0;
        }
    }
    return 0;
}