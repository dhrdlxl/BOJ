#include <iostream>

using namespace std;

const int MAX_OBSTACLE = 500001;

struct brokenInfo{
public:
    int brokenBlockCount;
    int section;
    brokenInfo(){}
    brokenInfo(int m_brokenBlockCount, int m_section)
    :brokenBlockCount(m_brokenBlockCount), section(m_section){}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H;
    cin >> N >> H;

    int obstacle[MAX_OBSTACLE][2];
    for (int index = 0; index <= H; index++)
    {
        obstacle[index][0] = 0;
        obstacle[index][1] = 0;
    }

    int odd, even;
    for (int index = 1; index <= N / 2; index++)
    {
        cin >> odd >> even;
        obstacle[odd][0]++;
        obstacle[even][1]++;
    }

    brokenInfo answer = brokenInfo(N, 0);
    int brokenCount = 0;
    int stalagmite = N / 2; // 석순
    int stalactite = 0; //종유석
    for (int section = 1; section <= H; section++)
    {
        stalagmite -= obstacle[section-1][0];
        stalactite += obstacle[H-(section-1)][1];
        brokenCount = stalagmite + stalactite;

        if(brokenCount < answer.brokenBlockCount)
        {            
            answer.brokenBlockCount = brokenCount;
            answer.section = 1;
        }
        else if(brokenCount == answer.brokenBlockCount)
        {
            answer.section++;
        }
    }

    cout << answer.brokenBlockCount << ' ' << answer.section <<'\n';
    return 0;
}