#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int L,C;
void printPasswd(char* a,int maxIndex,string s)
{
    if(s.size()==L)
    {
        int consonant=0, vowel=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                vowel++;
            else
                consonant++;
        }
        if(consonant>=2 && vowel>=1)
            cout<<s<<'\n';
        return;
    }
    if(maxIndex>=C)
        return;

    printPasswd(a,maxIndex+1,s+a[maxIndex]);
    printPasswd(a,maxIndex+1,s);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    char array[15];
    cin>>L>>C;

    for(int i=0;i<C;i++)
    {
        cin>>array[i];
    }

    sort(array,array+C);

    printPasswd(array,0,"");
    return 0;
}