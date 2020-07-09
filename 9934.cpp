#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 1024;

struct pos{
public:
    int left;
    int right;
    pos(){}
    pos(int m_left, int m_right):left(m_left), right(m_right){}
};

void binarySearch(int &nodeCount, int (&buildings)[MAX_SIZE])
{
    int left, right, mid;
    queue<pos> q;
    q.push(pos(0, nodeCount-1));

    int before = -1;
    while(!q.empty())
    {
        left = q.front().left;
        right = q.front().right;
        q.pop();

        mid = (left + right) / 2;
        
        if(before > mid)
            cout << '\n';

        cout << buildings[mid] << ' ';
        before = mid;

        if(left == right) 
            continue;

        q.push(pos(left , mid -1));
        q.push(pos(mid + 1, right));
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    int nodeCount = 1;
    for (int index = 1; index <= K; index++)
    {
        nodeCount *= 2;
    }
    nodeCount--;

    int buildings[MAX_SIZE];
    for (int index = 0; index < nodeCount; index++)
    {
        cin >> buildings[index];
    }

    binarySearch(nodeCount, buildings);

    return 0;
}