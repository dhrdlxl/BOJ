#include<iostream>
using namespace std;

//1�� �ڸ��� ���Ե� ���� ���� + 10�� �ڸ��� ���Ե� ���� ���� + ....
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int answer=0;
    cin>>N;

    for(int i=1;i<=N;i*=10)
    {
        answer+=N-i+1;
    }

    cout<<answer;
    return 0;
}