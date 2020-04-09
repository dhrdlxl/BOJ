#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    vector<string> words(N);
    vector<char> alphabet;
    for(int i=0;i<N;i++)
    {
        cin>>words[i];
        for(int j=0;j<words[i].size();j++)
        {
            alphabet.push_back(words[i][j]);
        }
    }
    //alphabet에 저장된 알파벳의 중복 제거
    sort(alphabet.begin(),alphabet.end());//unique함수가 앞뒤를 비교하므로 sort 필요
    alphabet.erase(unique(alphabet.begin(),alphabet.end()),alphabet.end());

    //순열에 사용할 수 생성
    vector<int> nums(alphabet.size());
    //size() 함수는 unsigned 형태로 값을 리턴하므로 size가 10일 때
    //9-10의 값이 음수가 되어야 하는데 unsigned형태로 출력되어 매우 큰 값이 된다
    //따라서 int형으로 변환
    for(int i=9, j=0;i>9-(int)alphabet.size();i--,j++)
    {
        nums[j]=i;
    }

    int answer=0;
    int table[256];
    do{
        //알파벳과 매칭되는 값(0~9)를 나타내는 table 갱신
        for(int i=0;i<alphabet.size();i++)
            table[alphabet[i]]=nums[i];
        
        int sum=0;
        for(int i=0;i<words.size();i++)
        {
            int value=0;
            for(int j=0;j<words[i].size();j++)
            {
                value=value*10+table[words[i][j]];
            }
            sum+=value;
        }
        if(sum>answer)answer=sum;
    }while(prev_permutation(nums.begin(),nums.end()));
    //더이상 반환할 순열 값이 없으면 false 있으면 true

    cout<<answer;
    return 0;
}