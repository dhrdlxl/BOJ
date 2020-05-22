#include <iostream>
#include <cassert>
using namespace std;

#define Assert(expression, message) assert(expression &&message)
const int MAXNUM = 50;

struct pos
{
public:
    int y;
    int x;
    int dir;
    pos(int m_y, int m_x, int m_dir) : y(m_y), x(m_x), dir(m_dir) {}
    pos() {}
};
class queue
{
private:
    pos arr[20000];
    int begin;
    int end;

public:
    queue() : begin(0), end(0) {}

    bool isEmpty()
    {
        return begin == end ? true : false;
    }
    void push(pos m_pos)
    {
        arr[end].y = m_pos.y;
        arr[end].x = m_pos.x;
        arr[end].dir = m_pos.dir;
        end++;
        return;
    }
    void pop()
    {
        if (!isEmpty())
            begin++;
        return;
    }
    int size()
    {
        return end - begin;
    }
    pos front()
    {
        Assert(!isEmpty(), "Empty Queue");
        if (!isEmpty())
            return arr[begin];
    }
};

int dY[4] = {-1, 1, 0, 0};
int dX[4] = {0, 0, -1, 1};

int min(int a, int b)
{
    return a < b ? a : b;
}

void ChangeDirection(const int &dir, int *arr)
{
    if (dir == 0 || dir == 1)
    {
        arr[0] = 2;
        arr[1] = 3;
    }
    else if (dir == 2 || dir == 3)
    {
        arr[0] = 0;
        arr[1] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    char Board[MAXNUM][MAXNUM];
    int Mask[MAXNUM][MAXNUM][4];
    pos StartDoor;
    pos EndDoor;
    bool CheckFirst = true;

    cin >> N;

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            cin >> Board[row][col];
            if (Board[row][col] == '#')
            {
                if (CheckFirst)
                {
                    StartDoor = pos(row, col, -1);
                    CheckFirst = false;
                }
                else
                {
                    EndDoor = pos(row, col, -1);
                }
            }

            for (int dir = 0; dir < 4; dir++)
            {
                Mask[row][col][dir] = MAXNUM * MAXNUM;
            }
        }
    }

    queue q;
    for (int dir = 0; dir < 4; dir++)
    {
        q.push(pos(StartDoor.y, StartDoor.x, dir));
        Mask[StartDoor.y][StartDoor.x][dir]=0;
    }

    while (!q.isEmpty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int dir = q.front().dir;

        q.pop();

        int cy = y + dY[dir];
        int cx = x + dX[dir];
        if (cy < 0 || cx < 0 || cy >= N || cx >= N)
            continue;

        if (Board[cy][cx] == '*')
            continue;
        else if (Board[cy][cx] == '.') //blank
        {
            if (Mask[cy][cx][dir] > Mask[y][x][dir])
            {
                Mask[cy][cx][dir] = Mask[y][x][dir];
                q.push(pos(cy, cx, dir));
            }
        }
        else if (Board[cy][cx] == '!')
        {
            int NewDir[2];
            ChangeDirection(dir, &NewDir[0]);

            if (Mask[cy][cx][dir] > Mask[y][x][dir])
            {
                Mask[cy][cx][dir] = Mask[y][x][dir];
                q.push(pos(cy, cx, dir));
            }
            if (Mask[cy][cx][NewDir[0]] > Mask[y][x][dir] + 1)
            {
                Mask[cy][cx][NewDir[0]] = Mask[y][x][dir] + 1;
                q.push(pos(cy, cx, NewDir[0]));
            }
            if (Mask[cy][cx][NewDir[1]] > Mask[y][x][dir] + 1)
            {
                Mask[cy][cx][NewDir[1]] = Mask[y][x][dir] + 1;
                q.push(pos(cy, cx, NewDir[1]));
            }
        }
        else if (Board[cy][cx] == '#')
        {
            if (Mask[cy][cx][dir] > Mask[y][x][dir])
            {
                Mask[cy][cx][dir] = Mask[y][x][dir];
            }
        }
    }

    int answer = MAXNUM * MAXNUM;
    for (int dir = 0; dir < 4; dir++)
    {
        answer = min(answer, Mask[EndDoor.y][EndDoor.x][dir]);
    }
    cout << answer;
    return 0;
}