#include<iostream>
using namespace std;

//1~9, 10~99, 100~999 범위를 차례대로 보면서 더해주는 방법
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int answer=0;
    cin>>N;

    long long end=10;
    for(int i=1;i<=9;i++)
    {
        if(N>end-1)
        {
            answer+=i*(end-end/10);
            end*=10;
        }
        else
        {
            answer+=i*(N-end/10+1);
            break;
        }
    }

    cout<<answer;
    return 0;
}