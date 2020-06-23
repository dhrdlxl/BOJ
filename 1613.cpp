#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool connected[401][401];

bool bfs(int start, const int &target, const vector<vector<int>> &relations, int &n)
{
    vector<bool> mask(n + 1, false);

    mask[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (connected[now][target] == true)
        {
            return true;
            break;
        }
        for (int index = 0; index < relations[now].size(); index++)
        {
            int next = relations[now][index];
            if (mask[next] == false)
            {
                mask[next] = true;
                q.push(next);
                connected[start][next] = true;
                connected[now][next] = true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> relations(n + 1);

    int from, to;
    for (int index = 0; index < k; index++)
    {
        cin >> from >> to;
        connected[from][to] = true;
        relations[from].push_back(to);
    }

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        cin >> from >> to;

        if (bfs(from, to, relations, n))
        {
            cout << -1 << '\n';
        }
        else if (bfs(to, from, relations, n))
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