#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kArray[12];
    int array[12];
    int k;

    while(cin>>k && k)
    {
        for(int i=0;i<k;i++)
        {
            cin>>array[i];
        }
        for(int i=0;i<6;i++)
        {
            kArray[i]=1;
        }
        for(int i=6;i<k;i++)
        {
            kArray[i]=0;
        }

        do{
            for(int i=0;i<k;i++)
            {
                if(kArray[i]==1)
                    cout<<array[i]<<" ";
            }
            cout<<'\n';
        }while(prev_permutation(kArray,kArray+k));
        cout<<'\n';
    }
    return 0;
}