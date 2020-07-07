#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 200001;

int getRouterCount(int &mid, int &N, int (&pos)[MAX_SIZE])
{
    int count = 1;
    int before = pos[0];
    for (int index = 1; index < N; index++)
    {
        if(pos[index] - before >= mid)
        {
            count++;
            before = pos[index];
        }
    }
    return count;
}

int binarySearch(int &N, int &C, int (&pos)[MAX_SIZE])
{
    int answer = 0;
    int left, right, mid;
    left = 1;
    right = pos[N - 1] - pos[0];
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (getRouterCount(mid, N, pos) < C)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            answer = mid;
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;

    int pos[MAX_SIZE];

    for (int index = 0; index < N; index++)
    {
        cin >> pos[index];
    }

    sort(pos, pos + N);

    cout << binarySearch(N, C, pos) << '\n';

    return 0;
}