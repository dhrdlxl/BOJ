#include <iostream>

using namespace std;

const int MAX_VALUE = 100000000;

int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

void floydWarshall(const int &n, int (&relations)[401][401])
{
    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (relations[u][k] != MAX_VALUE)
            {
                for (int v = 1; v <= n; v++)
                {
                    relations[u][v] = min(relations[u][v], relations[u][k] + relations[k][v]);
                }
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int relations[401][401];

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if (row == col)
            {
                relations[row][col] = 0;
            }
            else
            {
                relations[row][col] = MAX_VALUE;
            }
        }
    }

    int from, to;
    for (int index = 0; index < k; index++)
    {
        cin >> from >> to;
        relations[from][to] = 1;
    }

    floydWarshall(n, relations);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        cin >> from >> to;
        if (relations[from][to] != MAX_VALUE)
        {
            cout << -1 << '\n';
        }
        else if (relations[to][from] != MAX_VALUE)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
    return 0;
}