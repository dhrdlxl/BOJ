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
    //alphabet�� ����� ���ĺ��� �ߺ� ����
    sort(alphabet.begin(),alphabet.end());//unique�Լ��� �յڸ� ���ϹǷ� sort �ʿ�
    alphabet.erase(unique(alphabet.begin(),alphabet.end()),alphabet.end());

    //������ ����� �� ����
    vector<int> nums(alphabet.size());
    //size() �Լ��� unsigned ���·� ���� �����ϹǷ� size�� 10�� ��
    //9-10�� ���� ������ �Ǿ�� �ϴµ� unsigned���·� ��µǾ� �ſ� ū ���� �ȴ�
    //���� int������ ��ȯ
    for(int i=9, j=0;i>9-(int)alphabet.size();i--,j++)
    {
        nums[j]=i;
    }

    int answer=0;
    int table[256];
    do{
        //���ĺ��� ��Ī�Ǵ� ��(0~9)�� ��Ÿ���� table ����
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
    //���̻� ��ȯ�� ���� ���� ������ false ������ true

    cout<<answer;
    return 0;
}