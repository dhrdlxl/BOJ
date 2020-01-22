#include<iostream>
#include<list>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    short N,K,Survivor;
    list<short> cycle;
    cin>>N>>K;
    for(int i=1;i<=N;i++)cycle.push_back(i);

    list<short>::iterator del_index = cycle.begin();
    Survivor = N;
    cout<<'<';
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<(K-1)%Survivor;j++)
        {
            del_index++;
            if(del_index==cycle.end())del_index=cycle.begin();
            //end()�� ����Ʈ ������ ���� ��ĭ ���� �ּҸ� ����Ų��.
        }
        cout<<*del_index<<", ";
        del_index=cycle.erase(del_index);//erase�ϸ� ���� ���� ���� ��ȯ
        if(del_index==cycle.end())del_index=cycle.begin();
        Survivor--;
    }
    cout<<cycle.front()<<">";
    
    return 0;
}