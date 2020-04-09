#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<char,int> alphabet;
vector<string> words;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        words.push_back(s);
        for(int j=0;j<s.size();j++)
        {
            if(alphabet.count(s[j])==0)
            {
                alphabet[s[j]]=-1;
            }
        }
    }

    vector<int> num(alphabet.size());
    int size = alphabet.size();
    for(int i=9,j=0;i>9-size;i--,j++)
    {
        num[j]=i;
    }
    int answer=0;
    do{
        map<char,int>::iterator iter;
        int i=0;
        for(iter=alphabet.begin();iter!=alphabet.end();iter++,i++)
        {
            iter->second=num[i];
        }
        int sum=0;
        for(i=0;i<N;i++)
        {
            int value=0;
            for(int j=0;j<words[i].size();j++)
            {
                value=value*10+alphabet[words[i][j]];
            }
            sum+=value;
        }
        if(sum>answer)
            answer=sum;
    }while(prev_permutation(num.begin(),num.end()));

    cout<<answer;
    return 0;
}