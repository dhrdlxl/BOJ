#include <iostream>

using namespace std;

int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

void floydWarshall(const int &n, bool (&relations)[401][401])
{
    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (relations[u][k] == true)
            {
                for (int v = 1; v <= n; v++)
                {
                    relations[u][v] = (relations[u][v] || (relations[u][k] && relations[k][v]));
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

    bool relations[401][401];

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if (row == col)
            {
                relations[row][col] = true;
            }
            else
            {
                relations[row][col] = false;
            }
        }
    }

    int from, to;
    for (int index = 0; index < k; index++)
    {
        cin >> from >> to;
        relations[from][to] = true;
    }

    floydWarshall(n, relations);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        cin >> from >> to;
        if (relations[from][to] == true)
        {
            cout << -1 << '\n';
        }
        else if (relations[to][from] == true)
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