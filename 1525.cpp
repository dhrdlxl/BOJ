#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

const int ANSWER = 123456789;

int dY[4] = {0, 0, -1, 1};
int dX[4] = {-1, 1, 0, 0};

int bfs(int (&board)[9], int &start)
{
    int answer = 0;
    unordered_map<int, int> check;
    check[start] = 0;
    queue<int> q;
    q.push(start);

    char str[9];

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        int now;
        int copyNum = num;
        for (int digit = 100000000, index = 0; digit > 0; digit /= 10, index++)
        {
            int m_num = copyNum / digit;
            copyNum %= digit;
            if (m_num == 9)
            {
                now = index;
            }
            str[index] = '0' + m_num;
        }

        int y = now / 3;
        int x = now % 3;

        for (int index = 0; index < 4; index++)
        {
            int newY = y + dY[index];
            int newX = x + dX[index];
            if (newY < 0 || newY >= 3 || newX < 0 || newX >= 3)
                continue;
            int next = newY * 3 + newX;

            char temp;
            char copyStr[9];
            for (int i = 0; i < 9; i++)
            {
                copyStr[i] = str[i];
            }
            temp = copyStr[now];
            copyStr[now] = copyStr[next];
            copyStr[next] = temp;

            int nextNum = 0;
            for (int i = 0; i < 9; i++)
            {
                nextNum = nextNum * 10 + (copyStr[i] - '0');
            }

            if (check.count(nextNum) == 0)
            {
                if (ANSWER == nextNum)
                    return check[num] + 1;
                check[nextNum] = check[num] + 1;
                q.push(nextNum);
            }
        }
    }
    if(check.count(ANSWER) == 0 )
        return -1;
    else
        return check[ANSWER];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int board[9];
    int start = 0;
    for (int index = 0; index < 9; index++)
    {
        cin >> board[index];
        if (board[index] == 0)
        {
            board[index] = 9;
        }
        start = start * 10 + board[index];
    }
    queue<int> q;

    cout << bfs(board, start);
    return 0;
}