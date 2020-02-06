#include<iostream>
#include<vector>
using namespace std;

void Lotto(int max, int* array,int index,vector<int> answer)
{
    if(answer.size()==6)
    {
        for(int i=0;i<6;i++)
            cout<<answer[i]<<" ";
        cout<<'\n';
        return;
    }
    if(index>=max) return;
    answer.push_back(array[index]);
    Lotto(max,array,index+1,answer);
    answer.pop_back();
    Lotto(max,array,index+1,answer);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    int kArray[12];
    vector<int> vec;
    while(cin>>k && k)
    {
        for(int i=0;i<k;i++)
        {
            cin>>kArray[i];
        }

        Lotto(k,kArray,0,vec);
        cout<<'\n';
    }
    return 0;
}