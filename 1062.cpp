#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int mask[50];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K;
    cin>>N>>K;

    string s;
    if(K<5)//antic
    {
        cout<<0;
        return 0;
    }

    for(int i=0;i<N;i++)
    {
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            mask[i]|=(1<<(s[j]-'a'));
        }
    }
    int antic_Mask = 0;
    antic_Mask|=(1<<('a'-'a'));
    antic_Mask|=(1<<('n'-'a'));
    antic_Mask|=(1<<('t'-'a'));
    antic_Mask|=(1<<('i'-'a'));
    antic_Mask|=(1<<('c'-'a'));
    
    vector<int> permute('z'-'a'+1);
    for(int i=0;i<K;i++)
    {
        permute[i]=1;
    }
    int answer=0;
    do{
        int bitMask = 0;
        for(int i=0;i<'z'-'a'+1;i++)
        {
            if(permute[i]==1)
            {
                bitMask|=(1<<i);
            }
        }

        if((antic_Mask&((1<<26)-1-bitMask))!=0) continue;
        //if((bitMask&antic_Mask)!=antic_Mask) continue; //같은 의미
        int count=0;

        for(int i=0;i<N;i++)
        {
            if((mask[i]&((1<<26)-1-bitMask))==0)
            {
                count++;
            }
        }
        if(answer<count)answer=count;
    }while(prev_permutation(permute.begin(),permute.end()));
    
    cout<<answer;
    return 0;
}