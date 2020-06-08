#include <iostream>
#include <cassert>

using namespace std;

const int MAX_QUEUE_SIZE = 10001;
const int NOT_VISITIED = -10;
const int START = -1;

template <typename T>
class queue
{
private:
    T arr[MAX_QUEUE_SIZE];
    int begin;
    int end;

public:
    queue() : begin(0), end(0) {}

    bool empty()
    {
        if (begin == end)
            return true;
        return false;
    }
    void push(T inputValue)
    {
        assert((end < MAX_QUEUE_SIZE) && "queue overflow");
        if (end < MAX_QUEUE_SIZE)
        {
            arr[end] = inputValue;
            end++;
        }
        return;
    }
    void pop()
    {
        if (!empty())
        {
            begin++;
        }
        return;
    }
    T front()
    {
        assert(!(begin == end) && "Empty Queue");
        return arr[begin];
    }
};

void Print(int (&from)[MAX_QUEUE_SIZE], char (&operations)[MAX_QUEUE_SIZE], int num)
{
    if (from[num] == -1)
        return;
    Print(from, operations, from[num]);
    cout << operations[num];
}

void bfs(const int &A, const int &B)
{
    int from[MAX_QUEUE_SIZE];
    char operations[MAX_QUEUE_SIZE];
    for (int index = 0; index < MAX_QUEUE_SIZE; index++)
    {
        from[index] = NOT_VISITIED;
    }

    from[A] = START;

    queue<int> q;
    q.push(A);

    while (!q.empty())
    {
        if (q.front() == B)
        {
            Print(from, operations, B);
            break;
        }

        int now = q.front();
        q.pop();

        int next;

        //D
        next = 2 * now % 10000;
        if (from[next] == NOT_VISITIED)
        {
            q.push(next);
            from[next] = now;
            operations[next] = 'D';
        }

        //S
        next = (now - 1 + 10000) % 10000;
        if (from[next] == NOT_VISITIED)
        {
            q.push(next);
            from[next] = now;
            operations[next] = 'S';
        }

        //L
        next = (now % 1000 * 10) + (now / 1000);
        if (from[next] == NOT_VISITIED)
        {
            q.push(next);
            from[next] = now;
            operations[next] = 'L';
        }

        //R
        next = (now / 10) + (now % 10 * 1000);
        if (from[next] == NOT_VISITIED)
        {
            q.push(next);
            from[next] = now;
            operations[next] = 'R';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int testCase = 0; testCase < T; testCase++)
    {
        int A, B;
        cin >> A >> B;

        bfs(A, B);
        cout<<'\n';
    }
    return 0;
}