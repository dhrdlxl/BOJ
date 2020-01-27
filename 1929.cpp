#include<iostream>
using namespace std;

bool check[1000001];

void eratosthenes(int n){
    check[1]=true;
    for(int i=2;i*i<=n;i++)
    {
        if(check[i]==false)//prime
        {
            for(int j=i+i;j<=n;j+=i)//아래 설명
            {
                check[j]=true;
            }
        }
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M,N;
    cin>>M>>N;

    eratosthenes(N);

    for(int i=M;i<=N;i++)
    {
        if(!check[i])
        cout<<i<<'\n';
    }
    return 0;
}

/*
# 만약 eratosthenes 함수 내부에서 소수를 모두 구하기 위해
for(i=2;i<=n;i++) 을 사용한다면 j=i*i 를 사용 시 int 범위를
초과하는 경우가 발생하므로 i+i를 꼭 사용해야 한다.

# 해당 문제 에서는 i*i<=n 이므로 j=i*i를 사용해도 상관없다.
*/