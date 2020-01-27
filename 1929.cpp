#include<iostream>
using namespace std;

bool check[1000001];

void eratosthenes(int n){
    check[1]=true;
    for(int i=2;i*i<=n;i++)
    {
        if(check[i]==false)//prime
        {
            for(int j=i+i;j<=n;j+=i)//�Ʒ� ����
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
# ���� eratosthenes �Լ� ���ο��� �Ҽ��� ��� ���ϱ� ����
for(i=2;i<=n;i++) �� ����Ѵٸ� j=i*i �� ��� �� int ������
�ʰ��ϴ� ��찡 �߻��ϹǷ� i+i�� �� ����ؾ� �Ѵ�.

# �ش� ���� ������ i*i<=n �̹Ƿ� j=i*i�� ����ص� �������.
*/