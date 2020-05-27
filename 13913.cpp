#include <iostream>
#include <cassert>
using namespace std;

const int ROADSIZE = 100000;

struct Mask
{
public:
    int visit;
    int prevPos;
    Mask() : visit(-1), prevPos(-1) {}
};

class queue
{
private:
    int begin;
    int end;
    int arr[ROADSIZE + 1];

public:
    queue() : begin(0), end(0) {}

    bool isEmpty()
    {
        return (end - begin) == 0 ? true : false;
    }
    void push(int m_input)
    {
        assert(!(end >= ROADSIZE + 1) && "queue index overflow");
        arr[end] = m_input;
        end++;
        return;
    }
    void pop()
    {
        assert(isEmpty() != true && "queue is empty, can't pop");
        begin++;
    }
    int front()
    {
        if (!isEmpty())
        {
            return arr[begin];
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    Mask mask[ROADSIZE + 1];
    queue q;
    q.push(N);
    mask[N].visit++;

    while (!q.isEmpty())
    {
        int pos = q.front();
        q.pop();

        if (pos - 1 >= 0)
        {
            if (mask[pos - 1].visit == -1)
            {
                mask[pos - 1].visit = mask[pos].visit + 1;
                mask[pos - 1].prevPos = pos;
                q.push(pos - 1);
            }
        }
        if (pos + 1 <= ROADSIZE)
        {
            if (mask[pos + 1].visit == -1)
            {
                mask[pos + 1].visit = mask[pos].visit + 1;
                mask[pos + 1].prevPos = pos;
                q.push(pos + 1);
            }
        }
        if (pos * 2 <= ROADSIZE)
        {
            if (mask[pos * 2].visit == -1)
            {
                mask[pos * 2].visit = mask[pos].visit + 1;
                mask[pos * 2].prevPos = pos;
                q.push(pos * 2);
            }
        }
    }
    cout << mask[K].visit << '\n';

    int reverse[ROADSIZE + 1];
    int reverseSize = 0;
    int prevIndex = K;
    while (prevIndex != -1)
    {
        reverse[reverseSize++] = prevIndex;
        prevIndex = mask[prevIndex].prevPos;
    }
    for (int index = reverseSize - 1; index >= 0; index--)
    {
        cout << reverse[index] << ' ';
    }
    return 0;
}