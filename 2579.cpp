#include <iostream>

using namespace std;

const int MAX_SIZE = 301;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int floorCount;
    cin >> floorCount;

    int floorCosts[MAX_SIZE];
    for (int index = 0; index < floorCount; index++)
    {
        cin >> floorCosts[index];
    }

    int dp[MAX_SIZE][2]; //conitnued, not continued

    dp[0][0] = floorCosts[0];
    dp[0][1] = floorCosts[0];
    dp[1][0] = floorCosts[0] + floorCosts[1];
    dp[1][1] = floorCosts[1];

    for (int index = 2; index < floorCount; index++)
    {
        dp[index][0] = floorCosts[index] + dp[index - 1][1];
        dp[index][1] = floorCosts[index] + max(dp[index - 2][0], dp[index - 2][1]);
    }

    cout << max(dp[floorCount - 1][0], dp[floorCount - 1][1]);

    return 0;
}